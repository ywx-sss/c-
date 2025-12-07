#include <bits/stdc++.h>
using namespace std;
int main() {
	int a[16]={1},n,w,sum=0;
    cin>>n>>w;
    for(int i=1;i<n;i++){
    	a[i]=1;
	}
    a[n]=w;
    while(1){	
    	for(int i=1;i<=n;i++){
    		cout<<a[i];
		}
		cout<<endl;
		if(a[1]==w)break;
		a[n-1]++;
		for(int i=n-1;i>0;i--){
			if(a[i]>w){
				a[i-1]++;
				for(int j=i-1;j<n-1;j++)a[j+1]=a[j];
			}
		}
	}
	return 0;
}