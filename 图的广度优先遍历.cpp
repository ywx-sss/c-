#include <stdio.h>
#include <string.h>

int to[200],nt[200],hd[30],ec;
char v[30];

void add(int u,int w){
	to[ec] = w;
	nt[ec] = hd[u];
	hd[u] = ec++;
}

int main(){
	int n = 0;
	for(int i = 0; i < 30; i++){
		hd[i] = -1;
	}
	while(1){
		char c;
		if(scanf(" %c",&c) != 1){
			return 0;
		}
		if(c == '*'){
			break;
		}
		v[n++] = c;
	}
	while(1){
		int a,b;
		if(scanf("%d,%d",&a,&b) != 2){
			return 0;
		}
		if(a == -1 && b == -1){
			break;
		}
		add(a,b);
		add(b,a);
	}
	printf("the ALGraph is\n");
	for(int i = 0; i < n; i++){
		printf("%c",v[i]);
		for(int e = hd[i]; e != -1; e = nt[e]){
			printf(" %d",to[e]);
		}
		printf("\n");
	}
	int q[30];
	int l = 0,r = 0;
	int vis[30] = {0};
	printf("the Breadth-First-Seacrh list:");
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			vis[i] = 1;
			q[r++] = i;
			while(l < r){
				int x = q[l++];
				printf("%c",v[x]);
				for(int e = hd[x]; e != -1; e = nt[e]){
					int y = to[e];
					if(!vis[y]){
						vis[y] = 1;
						q[r++] = y;
					}
				}
			}
		}
	}
	printf("\n");
	return 0;
}