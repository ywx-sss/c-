#include <bits/stdc++.h>
using namespace std;
int main()
{
    int p,la,tian,m,n,sum=0,num=0,a[3005],b[3005],x=1,ans=0;
    cin>>p>>m>>n;
    for(int i=1;i<=p;i++){
    	cin>>la>>tian;
    	if(la>=m||tian<=n||tian-la<0){	
		continue;
		}
    	a[sum]=tian-la;
    	sum++;    	
	}
	sort(a,a+sum);
	b[0]=a[0];
	for(int i=0;i<sum;i++){
		if(b[num]!=a[i]){
			num++;
			b[num]=a[i];
		}
	}
	for(int i=0;i<num;i++){
		if(b[i]+1==b[i+1])x++;
		else x=1;
		ans=max(ans,x);
		cout<<x;
	}
	 cout<<ans;	
}
/*
9
5000 1
1 100
2 100
1 100
2 100
3 100
1 100
2 100
3 100
4 100
*/		                                            