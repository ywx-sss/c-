#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,hang=1,lie=1,num=1,flag=1;
	cin>>n;
	int a[n+1][n+1];
	while(hang!=n||lie!=n){
	    a[hang][lie]=num; 
        if(flag==1)lie++;
        if(flag==2){
            lie--;hang++;
        }  
        if(flag==3)hang++; 
        if(flag==4){
            lie++;hang--;
        }  
        if(flag==1&&hang==1)flag=2;
        if(flag==1&&hang==n)flag=4;
        if(flag==3&&lie==1)flag=4;
        if(flag==3&&lie==n)flag=2;
        if(flag==2&&lie==1&&hang!=n)flag=3;
        if(flag==2&&hang==n)flag=1;
        if(flag==4&&hang==1&&lie!=n)flag=1;
        if(flag==4&&lie==n)flag=3; 
        num++;
    }
    a[n][n]=n*n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j!=1)printf("%3d",a[i][j]);
            else printf("%2d",a[i][j]);
        }
        cout<<endl;
    }
    return 0;
}