#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n,a[10005],ans=0,l=0;
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	sort(a,a+n);
	while(l!=n-1){
		l++;
		a[l]=a[l-1]+a[l];
		ans+=a[l];
		sort(a+l,a+n);
	}
	cout<<ans<<endl;
}      