#include<bits/stdc++.h>
using namespace std;
typedef struct{
    int x, y, r; 
}circle;
typedef struct {
    double x; bool type; 
}info;
int n,num;
circle a[1005],b[1005];
bool cmp(info a, info b) {
    return a.x<b.x; 
}
double f(double pos) {
	double ans=0;
	int total=0; info tmp[2005];
	for (int i=1;i<=n;i++) {
		double d=a[i].r*a[i].r-(a[i].x-pos)*(a[i].x-pos);
		if (fabs(d)<=1e-8){
		continue;
		}//自适应Simpson精度判定
		d=sqrt(d);
		tmp[++total]=(info){a[i].y-d,true};
		tmp[++total]=(info){a[i].y+d,false};
	}
	sort(tmp+1,tmp+total+1,cmp);
	int cnt=0; 
	double last=0;
	for (int i=1;i<=total;i++) {
		if (tmp[i].type){
			if (++cnt==1) last=tmp[i].x;
		} 
		else{
		    if (--cnt==0){
		        ans+=tmp[i].x-last;
		    }
		}
	}
	return ans;
}
double Simpson(double l, double r) {
	double mid=(l+r)/2;
	return (f(l)+4*f(mid)+f(r))/6*(r-l);
	//复习见https://blog.csdn.net/VictoryCzt/article/details/80660113
}
double calc(double l, double r, double now) {
    //自适应重点，有分治思想
	double mid=(l+r)/2;
	double nowl=Simpson(l,mid);
	double nowr=Simpson(mid,r);
	if(fabs(now-nowl-nowr)<=1e-8){
	    return now;
	}//自适应Simpson精度判定
	else{
	    return calc(l, mid, nowl) + calc(mid, r, nowr);
	}
}
int main() {
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].r;	
	}
	int left=1e9,right=-1e9;
	for(int i=1;i<=n;i++) {
		left=min(left,a[i].x-a[i].r);
		right=max(right,a[i].x+a[i].r);
	}
	num=0;
	for (int i=1;i<=n;i++){
		b[++num]=a[i];
	}
	double ans=0;
	for (int i=left;i<right;i++) {
		n=0;
		for (int j=1;j<=num;j++)
			if (i>=b[j].x-b[j].r&&i<b[j].x+b[j].r)a[++n]=b[j];
		ans+=calc(i,i+1,Simpson(i,i+1));
	}
	printf("%.3lf\n", ans);
	return 0;
}