#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b){
    return !b ? a : gcd(b, a%b);
}
int main()
{
    long long n,up[25],down[25],upa=1,downa=1;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>up[i]>>down[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			long long num=gcd(up[i],down[j]);
			up[i]/=num;down[j]/=num;
		}
	}
	for(int i=1;i<=n;i++){
		upa*=up[i];
		downa*=down[i];
	}
	if(downa==1||upa==0)cout<<upa<<endl;
	else cout<<upa<<"/"<<downa<<endl;
}