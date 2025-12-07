#include<bits/stdc++.h>
using namespace std;  
int main(){  
    long long a;
    bool flag=0;
    cin>>a;
    for(int i=2;i<=a/2;i++){
    	for(int j=2;j<=a/2;j++){
    		if((i%j==0&&i!=j)||((a-i)%j==0&&(a-i)!=j)){
    			flag=1;
	     	}
		}
		if(flag==0){
		cout<<a<<"="<<i<<"+"<<a-i<<endl;
		}
		flag=0;
	}
    return 0;  
}  