#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;
void dfs( int N, int A, int B, vector<int> &a,vector<int> &b, int time, int t[])
{
	if(A==B)
	{
 	t[time]=1;
	b[0]=-1;//随便找的值，用于判断是否有结果，否则输出-1
	return;
	}
	if(A<=0||A>N)
{
return;
}
if(a[A]==0) return;
if(b[A]==1)
{
return;
}
else
{
b[A]=1;//记录来过
dfs(N,A+a[A],B,a,b,time+1,t);
dfs(N,A-a[A],B,a,b,time+1,t);
}
}
int main()
{
int N,A,B;
int time=0;//记录次数
int t[10000]={0};//用于给结果排序找最小值
cin >> N >> A >> B;
vector<int> a(N+1);//a数组存储各个楼层能走的步数
vector<int> b(N+1);//b数组记录楼层来没来过
a[0]=0;b[0]=0;//从1层到N层取值，0层不采用
for(int i=1;i<=N;i++) 
{
cin >> a[i];
b[i]=0;
}
dfs(N,A,B,a,b,0,t);
if(b[0]!=-1) cout << -1 << endl;
for(int i=0;i<10000;i++)
{
if(t[i]==1)
{
printf("%d\n",i);
break;
}
}
return 0;
}