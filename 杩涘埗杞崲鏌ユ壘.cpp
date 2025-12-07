#include<bits/stdc++.h>
using namespace std;
string ans="";
void itoaa(int n,int i){
	string a[16]={"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
	n/=i;n/=i;
	while(n!=0){
		ans+=a[n%i];
		n/=i;
	}
	return;
}
int main(){
	int n,flag=0;
	string s;
	cin>>n;
	getline(cin,s);
	for(int i=2;i<=16;i++){
		if(n%i==0&&(n/i)%i==0){
		    itoaa(n,i);
		    cout<<i<<" ";
		    for(int j=ans.size()-1;j>=0;j--){
		    	cout<<ans[j];
			}
			cout<<"00";
		    flag=1;
		    break;
	    }
	}
	if(flag==0)cout<<"impossible";
    return 0;	
}