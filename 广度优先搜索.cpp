#include <bits/stdc++.h>
using namespace std;
typedef struct{
	int x;
	int y;
	int step;
	int f;
}node;

int main(){
    node que[2505];
    int a[51][51]={0},book[51][51]={0},next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int head=1,tail=1,sx,sy,zx,zy,tx,ty,n,m,flag=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin>>a[i][j];
		}
	}
	cin>>sx>>sy>>zx>>zy;
	que[tail].x=sx;que[tail].y=sy;que[tail].step=0;que[tail].f=0;
	tail++;book[sx][sy]=1;
	while(head<tail){
		for(int i=0;i<=3;i++){
			tx=que[head].x+next[i][0];
			ty=que[head].y+next[i][1];
			if(tx<1||tx>n||ty<1||ty>m){
				continue;
			}
			if(a[tx][ty]==0&&book[tx][ty]==0){
				book[tx][ty]=1;
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].f=head;
				que[tail].step=que[head].step+1;
				tail++;
			}
			if(tx==zx&&ty==zy){
				flag=1;
				break;
			}
		}
		if(flag==1){
	     	break;
	    }
		head++;
	}
	cout<<que[tail-1].step<<endl;
	int t=tail-	1;
	while(t!=1){
		cout<<que[t].x<<" "<<que[t].y<<endl;
		t=que[t].f;
	}//递归
	return 0;
}