#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	int n,m,a,b;
	double ans=1,q,k;
	cin>>n>>m>>k;
	double num=k;
	double s[n+1];
	for(int i=1;i<=n-1;++i){
		cin>>a>>b;
		k+=a;k-=b;
		cout<<k<<endl;
		q=k/num;
		if(ans>q){
			ans=q;
		}
		cout<<fixed<<setprecision(3)<<q<<endl;
		s[i]=q;
	}
	for(int i=1;i<=n-1;i++){
		if(ans==s[i]){
			cout<<i<<",";
		}
	}
	cout<<endl;
	return 0;
}