#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n&&n!=0){
		vector<long long> h(n);
		for(int i=0;i<n;i++){
			cin>>h[i];
		}
		stack<int> st;
		long long ans=0;
		for(int i=0;i<n;i++){
			while(!st.empty()&&h[st.top()]>h[i]){
				int idx=st.top();
				st.pop();
				long long width=st.empty()?i:i-st.top()-1;
				ans=max(ans,h[idx]*width);
			}
			st.push(i);
		}
		while(!st.empty()){
			int idx=st.top();
			st.pop();
			long long width=st.empty()?n:n-st.top()-1;
			ans=max(ans,h[idx]*width);
		}
		cout<<ans<<endl;
	}
	return 0;
}