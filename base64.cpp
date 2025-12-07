#include <bits/stdc++.h>
#include <bitset>
using namespace std;
int main() {
	string base64="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	string s,er;
	int num=0,flag=0;
	getline(cin,s);
	for(char c:s){
	    bitset<8> bs(c);
		er+= bs.to_string();	
	}	
	if(s.size()%3==1){
	    er+="0000";flag=2;
	}
	if(s.size()%3==2){
	    er+="00";flag=1;
	}
	for(int i=0;i<=er.size();i++){
		if(i%6==0&&i!=0){
			cout<<base64[num];
			num=0;
		}	
		num+=pow(2,5-i%6)*(int(er[i])-48);
	}
	if(flag==1)cout<<"=";
	if(flag==2)cout<<"==";
	cout<<endl;
	return 0;
}

