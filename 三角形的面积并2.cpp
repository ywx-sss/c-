#include <bits/stdc++.h>
using namespace std;
const int MAXN=205;
const double eps=1e-10;
double sqr(double x){ 
	return x*x; 
}
int dcmp(double x) {
    return x<-eps?-1:x<eps?0:1;
}
int n,tot,st,ed;
struct node {
    double x,l,r,y,v;
    node(){}
    node(double x, double l, double r, double y, double v):x(x), l(l), r(r), y(y), v(v){}
    inline double L()const { return y < 0 ? x + y : x; }
    inline double R()const { return y > 0 ? x + y : x; }
    inline bool operator <(const node &o)const {
        return L() == o.L() ? R() < o.R() : L() < o.L();
    }
}arr[MAXN];
struct NODE {
    double l, r;
    NODE(){}
    NODE(double l, double r):l(l), r(r){}
    inline bool operator <(const NODE &o)const {
        return l == o.l ? r < o.r : l < o.l;
    }
}seq[MAXN];
inline double f(double x) {
    int cur = 0;
    for(int i = st; i <= ed; ++i)
        if(arr[i].L() < x && x < arr[i].R())
            seq[++cur] = NODE( arr[i].l + (x-arr[i].x)/arr[i].y * (arr[i].v-arr[i].l),
                               arr[i].r + (x-arr[i].x)/arr[i].y * (arr[i].v-arr[i].r) );
    sort(seq + 1, seq + cur + 1);
    double re = 0;
    for(int i = 1, j; i <= cur; i = j) { //求并集
        double L = seq[i].l, R = seq[i].r;
        for(j = i+1; j <= cur; ++j)
            if(dcmp(seq[j].l-R) > 0) break;
            else R = max(R, seq[j].r);
        re += R-L;
    }
    return re;
}
inline double Simpson(double L, double M, double R, double fL, double fM, double fR, int dep) {
    double M1 = (L + M) / 2, M2 = (M + R) / 2;
    double fM1 = f(M1), fM2 = f(M2);
    double g1 = (M-L) * (fL + 4*fM1 + fM) / 6, //注意这里套公式不要多写一个函数,那样会慢很多
        g2 = (R-M) * (fM + 4*fM2 + fR) / 6,
        g = (R-L) * (fL + 4*fM + fR) / 6;
    if(dep > 11 && fabs(g-g1-g2) < 1e-4) return g; //Simpson积分套路 : 加一个深度
    else return Simpson(L, M1, M, fL, fM1, fM, dep+1) + Simpson(M, M2, R, fM, fM2, fR, dep+1);
}
int main() {
	int t;
	cin>>t;
	for(int k=1;k<=t;k++){	
    	cin>>n;
    	double a, b, c, x, y, z;
    	for(int i = 1; i <= n; ++i) {
        	scanf("%lf%lf%lf%lf%lf%lf", &a, &x, &b, &y, &c, &z);
        	if(b < a || (b == a && y < x)) swap(a, b), swap(x, y); //排一下序
        	if(c < a || (c == a && z < x)) swap(a, c), swap(x, z);
        	if(c < b || (c == b && z < y)) swap(b, c), swap(y, z);
        	if(a == b)
            	arr[++tot] = node(b, x, y, c-b, z);
        	else if(b == c)
         	   	arr[++tot] = node(b, y, z, a-b, x);
       	 	else { //把三角形竖直切开拆成两个,方便后面计算
          		double tmp = x + (b-a)/(c-a) * (z-x);
          	  	arr[++tot] = node(b, min(tmp, y), max(tmp, y), a-b, x);
            	arr[++tot] = node(b, min(tmp, y), max(tmp, y), c-b, z);
        	}
    	}
    	sort(arr + 1, arr + tot + 1);
    	double ans = 0;
    	for(int i = 1, j; i <= tot; i = j) {
        	double L = arr[i].L(), R = arr[i].R();
        	for(j = i+1; j <= tot; ++j)
            	if(dcmp(arr[j].L()-R) > 0) break;
            	else R = max(R, arr[j].R());
        	double M = (L + R) / 2;
        	st = i, ed = j-1;
        	double fL = f(L), fM = f(M), fR = f(R);
        	ans += Simpson(L, M, R, fL, fM, fR, 0);
    	}
    	printf("%.2f\n", ans);
	}
}