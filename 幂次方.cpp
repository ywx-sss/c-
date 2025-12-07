#include <bits/stdc++.h>
using namespace std;
string ans;
void f(int num){
	string er;
	bitset<16> bs(num);
	er+= bs.to_string();
	for(int i=0;i<er.size();i++){
	   	if(er[i]=='1'){
	   		//cout<<15-i<<endl;
	   		if(15-i>1){
	   			ans+="2(";
				   f(15-i);
			}
	   		else if(15-i==1){
				ans+="2";
				if(er[15]=='1')ans+="+";
			}
	   		else if(15-i==0){
				ans+="2(0)";
			}
			if(15-i>1){
			    ans+=")";
			}
		}	
	}		
}
int main() {
	int n;
	cin>>n;
	f(n);	
	cout<<ans;
	return 0;
}

