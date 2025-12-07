#include <bits/stdc++.h>
using namespace std;
#define INF -1e7
#define N 100005
int num[N];
int Max(int cnt){
    int res=INF;
	int dp[N];
    dp[0]=0;
    for(int i=1;i<=cnt;i++){
        dp[i]=max(dp[i-1]+num[i],num[i]);
        res=max(dp[i],res);
    }
    return res;
}
int main(){
	int m,n;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>num[j];
		}
		cout<<Max(n)<<endl;
	}
}
/*
2
5
6 -1 5 4 -7
7
0 6 -1 1 -6 7 -5*/
