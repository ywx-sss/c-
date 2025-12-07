#include <iostream>
#include <bits/stdc++.h>
using namespace std; 
int main(){    
    int n,i;  
    double  station[10001]={2},min=1.1,a,b,k,m;  
    cin>>n>>m>>k;
    for (i=1; i<n; i++) {  
        cin>>a>>b;
        k = k+a-b;  
        if(k>m){
        	k=m;
		}
        station[i] = k/m;  
    }  
    for(i=1; i<n; i++){  
        cout<<fixed<<setprecision(3)<<station[i]<<endl;  
    }  
    for (i=0; i<n; i++) {  
        if (station[i] < min) {  
            min=station[i];       
        }  
    }  
    for (i = 0; i < n; i++) {  
        if (station[i] == min) {  
            cout<<i<<",";
        }  
    }  
    cout<<endl;
}  