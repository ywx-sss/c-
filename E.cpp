#include<bits/stdc++.h>
using namespace std;
long long Mod=998244353;
long long modpow(long long a,long long b,long long mod){
	long long result=1;
	while(b>0){
		if(b%2==1){
			result=(result*a)%mod;
		}
		a=(a*a)%mod;
		b/=2;
	}
	return result;
}
long long modd(long long a,long long b){
	long long inv=modpow(b,Mod-2,Mod);
	return (a*inv)%Mod;
}
int main() {
	string s;
	long long mu=0,muf=12,zi=1,zif=0;
    for(int t=1;t<=12;t++){
    	int flag=0;
    	cin>>s;
    	for(int i=0;i<4;i++){
    		if(s[i]=='1'||s[i]=='2')mu++;
    		if(s[i]=='2')flag=1;
		}
		if(flag!=1){
			continue;
		}
		else{
			zi*=5;
			zi*=(12/mu);
			zif+=zi;
			mu=0;
			zi=1;
	    }
	}
	if(zif%12==0){
		cout<<zif/muf;
		return 0;
	}
	if(zif%6==0){
		cout<<modd(zif/6,2);
		return 0;
	}
	if(zif%4==0){
		cout<<modd(zif/4,3);
		return 0;
	}
	if(zif%3==0){
		cout<<modd(zif/3,4);
		return 0;
	}
	if(zif%2==0){
		cout<<modd(zif/2,6);
		return 0;
	}
	cout<<modd(zif,12);
	return 0;
}