#include <bits/stdc++.h>
using namespace std;
int a[10],book[10],n=9,sum;//全局变量均为0；
void dfs(int step){
	if(step==n+1&&(a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6])==(a[7]*100+a[8]*10+a[9])){
        cout<<a[1]<<a[2]<<a[3]<<"+"<<a[4]<<a[5]<<a[6]<<"="<<a[7]<<a[8]<<a[9];
		cout<<endl;
		sum++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[i]==0){
			a[step]=i;
			book[i]=1;		
			dfs(step+1);
		    book[i]=0;
		}

	}
	return;
}
int main(){
    dfs(1);
    cout<<sum;
	return 0;
}
//1，2，3，4，5，6，7，8，9组成形如【】【】【】+【】【】【】=【】【】【】的等式有几个，不重叠