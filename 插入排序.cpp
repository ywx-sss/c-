#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,a[35];
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(!is_sorted(a,a+i+1)){
			sort(a,a+i+1);
			cout<<a[0];
			for(int j=1;j<n;j++){
				cout<<" "<<a[j];
			}
			cout<<endl;
		}
	}
	cout<<"Result:";
	for(int i=0;i<n;i++){
		cout<<" "<<a[i];
	}
	cout<<endl;
}