#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int isPrime(long long x)
{
	 if(x==1)
		return 0;
     if(x==2||x==3)
        return 1;
     if(x%6!=1&&x%6!=5)
        return 0;
     int tmp=sqrt(x);
     for(int i=5;i<=x;i+=6)
        if(x%i==0||x%(i+2)==0)
           return 0;
     return 1;
}//质数！！！！！
void fenjie(long long a){
    long long a2=0;
		if(isPrime(a)){
		cout<<" "<<a<<endl;
		return;
	}
	for(long long i=2;i<=a/2;i++){
		if(a%i==0){
			cout<<" "<<i<<" *";
			a2=a/i;
			break;
		}
	}

	fenjie(a2);
}
int main(int argc, char** argv) {
	long long n,a;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cout<<a<<" =";
		fenjie(a);
	}
	return 0;
}