#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 1e-9;
const double LOG_EPS = 1e-12;

// 静止壁：__int128分数计算，避免浮点数溢出（无变化）
double static_wall(double r0, double v, double a0, double b0, long long Tnum, long long Tden) {
    __int128 r0_int = (__int128)r0;
    __int128 a0_int = (__int128)a0;
    __int128 v_int = (__int128)v;
    __int128 L0_int = (__int128)b0 - a0_int;
    __int128 cycle_int = 2 * L0_int;
    __int128 numerator = (r0_int - a0_int) * Tden + v_int * Tnum;
    __int128 denominator = Tden;
    __int128 mod_base = cycle_int * denominator;
    __int128 rem_numerator = numerator % mod_base;
    if (rem_numerator < 0) rem_numerator += mod_base;
    double rem = (double)rem_numerator / (double)denominator;
    if (rem <= L0_int + EPS) {
        return (double)a0_int + rem;
    } else {
        return (double)(a0_int + L0_int) - (rem - L0_int);
    }
}

// 运动壁
double moving_wall(double r0, double v, double a0, double b0, double va, double vb, double T) {
    double v0 = v;
    double t1 = 0.0;
    double v_rel = 0.0;
    bool is_right_collision = (v0 > 0);

    // 步骤1：计算第一次碰撞时间 t1 和相对速度 v_rel
    if (is_right_collision) {
        v_rel = v0 - vb;
        if (v_rel <= EPS) {
            return r0 + v0 * T;
        }
        t1 = (b0 - r0) / v_rel;
    } else {
        v_rel = -v0 - va;
        if (v_rel <= EPS) {
            return r0 + v0 * T;
        }
        t1 = (r0 - a0) / v_rel;
    }

    t1 = max(t1, 0.0);
    if (t1 >= T + EPS) {
        return r0 + v0 * T;
    }

    // 步骤2：等比数列参数
    double k = va + vb;
    double q = 1.0 + k / v_rel;
    int k_max = 0;
    double q_k = 1.0;  // 预定义q_k，避免重复计算

    if (fabs(q - 1.0) < EPS) {
        // 特殊情况：q=1，碰撞时间间隔相等
        double delta_t = t1;
        k_max = (int)floor(T / delta_t);
        q_k = 1.0;  // q=1时，q^k_max = 1
    } else {
        // 优化：直接使用对数公式，然后快速验证微调
        double arg = (T * (q - 1.0)) / t1 + 1.0;
        if (arg < 1.0 + LOG_EPS) {
            k_max = 0;
            q_k = 1.0;
        } else {
            // 直接计算：k_max = floor(log(arg) / log(q))
            double log_arg = log(arg);
            double log_q = log(q);
            k_max = (int)floor(log_arg / log_q);
            k_max = max(0, k_max);
            
            // 计算q^k_max并验证（最多检查1次）
            double factor = t1 / (q - 1.0);
            q_k = pow(q, k_max);
            double S_t_k = factor * (q_k - 1.0);
            
            // 如果当前k_max太小，尝试k_max+1（最多一次）
            if (S_t_k <= T + EPS) {
                double q_k1 = q_k * q;  // q^(k_max+1)
                double S_t_k1 = factor * (q_k1 - 1.0);
                if (S_t_k1 <= T + EPS) {
                    k_max++;
                    q_k = q_k1;  // 保存q^(k_max+1)供后续使用
                }
            }
            // 如果当前k_max太大，回退（很少发生，通常不需要）
            else if (k_max > 0 && S_t_k > T + EPS * 10) {
                k_max--;
                q_k = pow(q, k_max);
            }
        }
    }

    // 步骤3：计算总碰撞时间 S_t 和总碰撞位移 S_s
    double S_t = 0.0;
    double S_s = 0.0;
    
    if (k_max > 0) {
        if (fabs(q - 1.0) < EPS) {
            S_t = t1 * k_max;
            // q=1时，S_s = v0 * t1 * (1 - (-1)^k_max) / 2
            if (k_max % 2 == 0) {
                S_s = 0.0;
            } else {
                S_s = v0 * t1;
            }
        } else {
            // 优化：重用已计算的q_k，避免重复pow调用
            double factor = t1 / (q - 1.0);
            S_t = factor * (q_k - 1.0);
            
            // 优化：交错等比数列求和，避免重复计算
            // S_s = v0 * t1 * (1 - (-q)^k_max) / (1 + q)
            // 注意：(-q)^k_max = (-1)^k_max * q^k_max
            double neg_q_k = (k_max % 2 == 0) ? q_k : -q_k;
            S_s = v0 * t1 * (1.0 - neg_q_k) / (1.0 + q);
        }
    }

    // 步骤4：剩余时间位移
    double delta_t = T - S_t;
    double v_k = (k_max % 2 == 1) ? (-v0) : v0;
    double s_rem = v_k * delta_t;

    return r0 + S_s + s_rem;
}

// 对外接口
double position(double r0, double v, double a0, double b0, double va, double vb, long long Tnum, long long Tden) {
    double T = (double)Tnum / (double)Tden;
    if (fabs(va) < EPS && fabs(vb) < EPS) {
        return static_wall(r0, v, a0, b0, Tnum, Tden);
    } else {
        return moving_wall(r0, v, a0, b0, va, vb, T);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int rx, ry, rz, vx, vy, vz;
        int x1, x2, y1, y2, z1, z2;
        int vx1, vx2, vy1, vy2, vz1, vz2;
        scanf("%d %d %d %d %d %d", &rx, &ry, &rz, &vx, &vy, &vz);
        scanf("%d %d %d %d %d %d", &x1, &x2, &y1, &y2, &z1, &z2);
        scanf("%d %d %d %d %d %d", &vx1, &vx2, &vy1, &vy2, &vz1, &vz2);

        long long Tnum = (long long)z2 - (long long)z1;
        long long Tden = (long long)(vz1 + vz2);
        double x = position(rx, vx, x1, x2, vx1, vx2, Tnum, Tden);
        double y = position(ry, vy, y1, y2, vy1, vy2, Tnum, Tden);
        double z = z2 - (double)vz2 * (double)Tnum / Tden;

        printf("%.9f %.9f %.9f\n", x, y, z);
    }
    return 0;
}

