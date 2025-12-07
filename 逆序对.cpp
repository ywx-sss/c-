#include <bits/stdc++.h>
using namespace std;
int a[5005], b[5005],ans;
void nixudui(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)>>1;
    nixudui(l,mid);
    nixudui(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r)
    {
        if(a[i]<=a[j]) 
            b[k++]=a[i++];
        else
        {
            b[k++]=a[j++];
            ans+=mid-i+1;
        }
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=r)
        b[k++]=a[j++];
    for(int p=l;p<=r;p++)
        a[p]=b[p],b[p]=0;
}
int main(){
	int n,m,ansday;
	long long unhappy=0x7fffffffffffffff;
		cin>>m;
		for(int j=1;j<=m;j++){
			cin>>a[j];
		}
		ans=0;
	cout<<ans<<endl;
	return 0;
}