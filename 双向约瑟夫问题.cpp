#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k,type=1;
    char c;
    cin>>n>>c>>k>>c>>m;
    int flag[n+5]={0},num=n,sum=k,baoshu=0,flagans[3]={0},jishu=0;
    if(n*k*m==0){
    	cout<<"n,m,k must bigger than 0."<<endl;
    	return 0;
	}
	if(k>n){
    	cout<<"k should not bigger than n."<<endl;
    	return 0;
	}
	while(num>0){
		if(type==1){
			if(flag[sum]==0){
				baoshu++;
				if(baoshu==m){
					flagans[1]=sum;
					type=2;
					baoshu=0;
				}
				else{	
					sum++;
					if(sum>n)sum-=n;
				}
			}
			else {
				sum++;
				if(sum>n)sum-=n;
			}
		}
		if(type==2){
			if(flag[sum]==0){
				baoshu++;
				if(baoshu==m){
					flagans[2]=sum;
					type=1;
					baoshu=1;
					sum++;
					if(sum>n)sum-=n;
				}
				else{	
					sum--;
					if(sum<1)sum+=n;
				}
			}
			else{	
				sum--;
				if(sum<1)sum+=n;
			}
		}
		if(flagans[1]!=0&&flagans[2]!=0){
			if(flagans[1]==flagans[2]){
				cout<<flagans[1]<<",";
				num--;
				flag[flagans[1]]=1;
			}
			else{
				cout<<flagans[1]<<"-"<<flagans[2]<<",";
				num-=2;
				flag[flagans[1]]=1;
				flag[flagans[2]]=1;
			} 
			flagans[1]=0;
			flagans[2]=0;
		}
		jishu++;
		if(jishu>100)break;
	}
	cout<<endl;
	return 0;
}