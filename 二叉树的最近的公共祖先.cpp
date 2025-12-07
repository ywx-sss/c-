#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,bitree[1005],num1,num2;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>bitree[i];
	}
	cin>>num1>>num2;
	if(bitree[num1]==0){
		cout<<"ERROR: T["<<num1<<"] is NULL"<<endl;
		return 0;
	}
	if(bitree[num2]==0){
		cout<<"ERROR: T["<<num2<<"] is NULL"<<endl;
		return 0;
	}
	while(num1!=num2){
		if(num1>num2){
			num1/=2;
		}
		if(num1<num2){
			num2/=2;
		}
	}
	cout<<num1<<" "<<bitree[num1]<<endl;
    return 0;
}