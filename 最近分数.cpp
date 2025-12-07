#include <bits/stdc++.h>
using namespace std;
long long huajian(long long a, long long b){
    return !b ? a : huajian(b, a%b);
}
int bijiao(long long x1,long long y1,long long x2,long long y2){
	if(x1*y2>x2*y1) return 1;
	if(x1*y2==x2*y1) return 2;
	if(x1*y2<x2*y1) return 3;
}
int main()
{
    long long x,y,n,besz,besm,zi,mu,ans1,ans2,flag=-1;
    cin>>x>>y>>n;
    besz=1e9,besm=1;
    x/=huajian(x,y);
    y/=huajian(x,y);
    if(y<=n){
	    cout<<x<<"/"<<y<<endl;
	    return 0;
    } 
    for(int i=1;i<=n;i++){
        mu=i*y;
        if((x*i-(x*i/y)*y)>((x*i/y+1)*y-x*i)){
		    zi=(x*i/y+1)*y-x*i;
		    flag=0;
		}
        else {
	        zi=x*i-(x*i/y)*y;
	        flag=1;
		}
        mu/=huajian(mu,zi);
        zi/=huajian(mu,zi);
        if(bijiao(zi,mu,besz,besm)==3){
       	    besz=zi;besm=mu;
       	    if(flag==0)ans1=x*i/y+1;
       	    else ans1=x*i/y;
       	    ans2=i;
	   }
	}
	ans1/=huajian(ans1,ans2);
    ans2/=huajian(ans1,ans2);
	cout<<ans1<<"/"<<ans2<<endl;
}