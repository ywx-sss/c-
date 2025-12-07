#include <cstdio>
#include <cstdlib>

struct Fraction
{
    int up;
    int down;
};
//求最大公约数
int gcd(int a, int b){
    return !b ? a : gcd(b, a%b);
}
//化简
Fraction reduction(Fraction result){
    if(result.down < 0){//分母为负，分子分母都变为相反数
        result.up = - result.up;
        result.down = - result.down;
    }

    if(result.up == 0){//如果分子为0，令分母为1
        result.down = 1;
    }else{//分子分母不为0，进行约分
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}

//加法
Fraction add(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down + f2.up *  f1.down;//分数和的分子
    result.down = f1.down * f2.down;//分数和的分母
    return reduction(result);//返回化简后的结果
}

//减法
Fraction minu(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;//分数差的分子
    result.down = f1.down * f2.down;//分数差的分母
    return reduction(result);//返回化简后的结果
}

//乘法
Fraction multi(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.up;//分数乘积的分子
    result.down = f1.down * f2.down;//分数乘积的坟墓
    return reduction(result);//返回化简后的结果
}

//除法
Fraction divide(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down;//分数商的分子
    result.down = f1.down * f2.up;//分数商的分母
    return reduction(result);//返回化解后的结果
}

//输出
void showResult(Fraction r){
    if(r.down == 1){//整数
        printf("%lld\n", (long long)r.up);
    }else if(abs(r.up) > r.down){//假分数
        printf("%d %d/%d\n", r.up/r.down, abs(r.up)%r.down, r.down);
    }else{//真分数
        printf("%d/%d\n", r.up, r.down);
    }
}

int main(int argc, char const *argv[])
{
    Fraction f1, f2, res;
    f1.up = 1;
    f1.down = 3;

    f2.up = 1;
    f2.down = 3;

//    res = add(f1, f2);
    res = minu(f1, f2);
//    res = multi(f1,f2);
//      res = divide(f1, f2);
    showResult(res);

    return 0;
}
