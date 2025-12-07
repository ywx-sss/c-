#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct E{
	int a,b,w;
} e[4005];

int f[1005];

int cmp(const void *x,const void *y){
	struct E *p = (struct E*)x;
	struct E *q = (struct E*)y;
	return p->w - q->w;
}

int fd(int x){
	if(f[x] == x) return x;
	f[x] = fd(f[x]);
	return f[x];
}

int main(){
	int n,m;
	if(scanf("%d%d",&n,&m) != 2) return 0;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].w);
	}
	for(int i = 1; i <= n; i++){
		f[i] = i;
	}
	qsort(e,m,sizeof(e[0]),cmp);
	int s = 0;
	int c = 0;
	for(int i = 0; i < m; i++){
		int x = fd(e[i].a);
		int y = fd(e[i].b);
		if(x != y){
			f[x] = y;
			s += e[i].w;
			c++;
			if(c == n - 1) break;
		}
	}
	if(c != n - 1){
		printf("-1\n");
	}else{
		printf("%d\n",s);
	}
	return 0;
}