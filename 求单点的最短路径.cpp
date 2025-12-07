#include <stdio.h>
#include <string.h>

int g[30][30],id[256],cnt,inf = 1000000000;
char nd[30];

void addc(char c){
	if(id[c] == -1){
		id[c] = cnt;
		nd[cnt++] = c;
	}
}

int main(){
	int n,e;
	char s;
	scanf("%d,%d,%c",&n,&e,&s);
	for(int i = 0; i < 256; i++){
		id[i] = -1;
	}
	for(int i = 0; i < 30; i++){
		for(int j = 0; j < 30; j++){
			if(i == j) g[i][j] = 0;
			else g[i][j] = inf;
		}
	}
	cnt = 0;
	addc(s);
	for(int i = 0; i < e; i++){
		char x,y;
		int w;
		scanf(" <%c,%c,%d>",&x,&y,&w);
		addc(x);
		addc(y);
		int a = id[x];
		int b = id[y];
		if(w < g[a][b]){
			g[a][b] = w;
		}
	}
	int d[30];
	int vis[30];
	for(int i = 0; i < cnt; i++){
		d[i] = inf;
		vis[i] = 0;
	}
	int st = id[s];
	d[st] = 0;
	for(int i = 0; i < cnt; i++){
		int k = -1;
		int mn = inf;
		for(int j = 0; j < cnt; j++){
			if(!vis[j] && d[j] < mn){
				mn = d[j];
				k = j;
			}
		}
		if(k == -1) break;
		vis[k] = 1;
		for(int j = 0; j < cnt; j++){
			if(!vis[j] && g[k][j] < inf && d[k] + g[k][j] < d[j]){
				d[j] = d[k] + g[k][j];
			}
		}
	}
	int ord[30];
	for(int i = 0; i < cnt; i++){
		ord[i] = i;
	}
	for(int i = 0; i < cnt - 1; i++){
		for(int j = i + 1; j < cnt; j++){
			if(nd[ord[i]] > nd[ord[j]]){
				int t = ord[i];
				ord[i] = ord[j];
				ord[j] = t;
			}
		}
	}
	for(int i = 0; i < cnt; i++){
		int u = ord[i];
		printf("%c:%d\n",nd[u],d[u]);
	}
	return 0;
}