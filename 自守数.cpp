#include<bits/stdc++.h>
using namespace std;
string anss,c[10]={"0","1","2","3","4","5","6","7","8","9"};
int flag;
bool iszishou(string a1) {
	string c1;
	int a[5005]={}, c[5005]={};
	int lena=a1.size(),lenc=lena*2;
	for (int i=0 ; i<lena; i++) {
		a[lena-i]=a1[i]-'0';
	}
	for (int i=1;i<=lena;i++) {
		for (int j=1;j<=lena;j++) {
			c[i+j-1]+=a[i]*a[j];
			c[i+j]+=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
	}
	while (lenc>1 && c[lenc] == 0) lenc--;
	while (lenc>=1) c1 += c[lenc--] + '0';
	return c1.erase(0,c1.size()-a1.size())==a1;
}
void zishou(string a,int n,int i){
	if(flag==1)return;
	string ans=c[i]+a;
	if(iszishou(ans)){
		if(ans.size()==n){
			anss=ans;flag=1;
		}
		if(flag==1)return;
		zishou(ans,n,1);
	}
    if(i==9){
	    if(ans.size()==n){
	    	anss="0"+a;
	    	flag=1;
		}
		zishou(c[0]+a,n,1);
	}
	i++;
    zishou(a,n,i);
}
int main() {
    int n;
    string a="5";
    cin>>n;
    if(n==1){
	    cout<<"1"<<endl<<"5"<<endl<<"6"<<endl;
	    return 0;
	}
    zishou(a,n,1);
    if(49<=int(anss[0])&&int(anss[0])<=52) {
	    cout<<anss<<endl;
	}
    if(anss[0]!=57){
        for(int i=0;i<anss.size();i++){
            if(i==anss.size()-1)cout<<"6"<<endl;
        	else cout<<int(57-int(anss[i]));
	    }  
    }
    if(53<=int(anss[0])&&int(anss[0])<=57){
    	cout<<anss<<endl;
	}
}
