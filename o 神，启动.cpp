#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,sum=0;
	cin>>n;
	for(long long  i=1;;i++){
		if((i+1)*i/2<=n&&(i+2)*(i+1)/2>n){
			sum=i;
			break;
		}
	}
	cout<<sum;
	return 0;
}