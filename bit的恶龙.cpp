#include<bits/stdc++.h>
using namespace std;
int book[205]={0},num[205],n;
void dfs(int st,int en,int step){
	cout<<st<<" "<<en<<" "<<step<<endl;
	book[st]=1;
	if(st+num[st]==en||st+num[st]==en){
		cout<<step;
		return;
	}
	if(book[st+num[st]]==1&&book[st+num[st]]==1){
		cout<<-1;
		return;
	}
	if(st+num[st]<=n){
		dfs(st+num[st],en,step+1);
	}
	if(st-num[st]>0){
		dfs(st-num[st],en,step+1);
	}
}
int main() {
    int a,b;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
    	cin>>num[i];
	}
	dfs(a,b,1);
	return 0;
}