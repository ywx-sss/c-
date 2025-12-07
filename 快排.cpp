#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100001],b[100001],c[100001],d[100001];
void quick_sort(int l,int r){
	if (l>=r) return;
	int mid=rand()%(r-l+1)+l;
	int tb=0,tc=0,td=0;
	for (int i=l;i<=r;i++){
		if (a[i]<a[mid]) b[++tb]=a[i];
		else if (a[i]>a[mid]) c[++tc]=a[i];
		else d[++td]=a[i];
	}
	for (int i=1;i<=tb;i++) a[l+i-1]=b[i];
	for (int i=1;i<=td;i++) a[l+i-1+tb]=d[i];
	for (int i=1;i<=tc;i++) a[l+i-1+tb+td]=c[i];
	quick_sort(l,l+tb-1);
	quick_sort(l+tb+td,r);
}
signed main(){
	srand((int)time(0));
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	quick_sort(1,n);
	for (int i=1;i<=n;i++) cout<<a[i]<<' ';
	return 0;
}