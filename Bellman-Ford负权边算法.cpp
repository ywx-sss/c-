#include <bits/stdc++.h>
using namespace std;
int main(){
    int dis[11],u[11],v[11],w[11],n,m;
    int inf=pow(2,18);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>u[i]>>v[i]>>w[i];
        dis[i]=inf;
	}
	dis[1]=0;
	//Bellman-Ford
	for(int k=1;k<=n-1;k++){//n-1次松弛操作
	//优化check=0
        for(int i=1;i<=m;i++){//对每条边操作
        	if(dis[v[i]]>dis[u[i]]+w[i]){//1距离终点的距离>距离起点的位置+路径距离；
        		dis[v[i]]=dis[u[i]]+w[i];
        		//check=1
			}
		}
		//if(check==0)break;
    }
    /*负权回路检验
    flag=0;
    for(int i=1;i<=m;i++){
    if(dis[v[i]]>dis[u[i]]+w[i])n-1次松弛后还会更新
    flag=1;
	}
	if(flag==1)cout<<"此图有负权回路“；*/
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<" ";
	}
	return 0;
}//队列优化可行类似广度优先搜索；