#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[11],swap,sum=0;
	double num=0;
	for(int i=1;i<=10;i++){
	    cin>>a[i];
	    num+=a[i];
    }
    num/=10;
    for(int i=1;i<=10;i++){
    	for(int j=i;j<=10;j++){
    		if(a[i]<=a[j]){
    			swap=a[i];
    			a[i]=a[j];
    			a[j]=swap;
			}
		}
	}
	for(int i=1;i<=10;i++){
		cout<<a[i]<<" ";
		if(a[i]>=num)sum++;
	}
	cout<<endl<<num<<endl<<sum;
	return 0;
}