#include <bits/stdc++.h>
using namespace std;
int num=0;
void count(int n,int m){
	if(n<m+1){		
		return;
	}
	else if(n==m+1){
		num+=1;
		return;
	}
	else{
		n=n-(m+1);	
		num+=1;
		int layer=1;	
		if(n==0||layer>m){		
			return;
		}
		int book;
		book=pow(2,layer)-1;				
		while(n-book>0){
			num+=pow(2,layer-1);
			layer++;			
			n-=book;
			book=pow(2,layer)-1;
			if(layer>m){
				return;
			}
		}
		if(n-book==0){
			num+=pow(2,layer-1);
			return;
		}	
		else{	
			count(n,layer-1);
		}				
	}	
}
int main() {
    int n,m,t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		num=0;		
		count(n,m);
		cout<<num<<endl;		
	}
    return 0;
}
