#include<bits/stdc++.h> 
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> t(m);
    vector<int> v(m);
    for(int i=0;i<m;i++){
    	cin>>t[i]>>v[i];
	}
	vector<vector<int>> dp(m+1, vector<int>(n+1,0));
	for (int i=0; i<m; i++) {
        for(int j=0; j<=n; j++) {
            if(j<t[i]) {
                dp[i+1][j] = dp[i][j];
            } 
			else{
                dp[i+1][j] = max(dp[i][j], dp[i][j-t[i]]+t[i]*v[i]);
            }
        }
    }
    
    cout<<dp[m][n]<<endl;
    
    return 0;
}