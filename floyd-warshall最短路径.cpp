#include <bits/stdc++.h>
using namespace std;
int main(){
    int map[11][11],n,m,b/*begin*/,d/*destion*/,s/*step*/;
    int ma=pow(2,10);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(i==j)map[i][j]=0;
    		else map[i][j]=ma;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>b>>d>>s;
		map[b][d]=s;
	}
	//floyd
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(map[i][k]+map[k][j]<map[i][j]){
					map[i][j]=map[i][k]+map[k][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}