#include <bits/stdc++.h>
using namespace std;
int main(){
    int e[21][21],dis[21],book[21],n,m,t1,t2,t3,min,point;
    int inf=pow(2,18);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(i==j)e[i][j]=0;
    		else e[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>t1>>t2>>t3;
		e[t1][t2]=t3;
	}
	for(int i=1;i<=n;i++){
	    dis[i]=e[1][i];
	    book[i]=0;
	}
	book[1]=1;
	//dijkstra
	for(int i=1;i<=n-1;i++){
		min=inf;
		for(int j=1;j<=n;j++){
			if(book[j]==0&&dis[j]<min){
				min=dis[j];
				point=j;
			}
		}
		book[point]=1;
		for(int k=1;k<=n;k++){
			if(e[point][k]<inf&&dis[k]>dis[point]+e[point][k]){
				dis[k]=dis[point]+e[point][k];
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<" ";
	}
	return 0;
}