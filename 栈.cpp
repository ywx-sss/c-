#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int q,n,a[100010],b[100010],zhan[100010],top1,top2;
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int k=1;k<=n;k++){
			cin>>b[k];
		}
		top1=0;top2=1;
		for(int m=1;m<=n;m++){
			top1++;
			zhan[top1]=a[m];
			while(zhan[top1]==b[top2]&&top1>0){
				top1--;
				top2++;
			}
		}
    	if(top1==0)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}