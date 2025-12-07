#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int vnum,arcnum,topo[55],path[100];

struct arc{
	int dir,weight;
};

struct v{
	char name[5];
	int innum,outnum,ve,vl,lnum;
	struct arc to[300];
};

struct v node[50];

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

int cmp2(const void *a,const void *b){
	return *(int*)b-*(int*)a;
}

void create(){
	char str[500];
	int len,q,k,i,a,b,c;
	scanf("%s",str);
	len = strlen(str);
	q = 0;
	k = 0;
	for(i = 0; i < len; i++){
		if(str[i] != ','){
			node[k].name[q++] = str[i];
		}else{
			node[k].name[q] = '\0';
			k++;
			q = 0;
		}
	}
	node[k].name[q] = '\0';
	getchar();
	for(i = 0; i < arcnum; i++){
		scanf("<%d,%d,%d>",&a,&b,&c);
		node[b].innum++;
		node[a].outnum++;
		node[a].to[node[a].lnum].dir = b;
		node[a].to[node[a].lnum].weight = c;
		node[a].lnum++;
		getchar();
	}
	for(i = 0; i < vnum; i++){
		qsort(node[i].to,node[i].lnum,sizeof(node[i].to[0]),cmp);
	}
}

int topo_sort(){
	int *stk,u,v,top,cnt,i;
	stk = (int*)malloc(sizeof(int)*vnum);
	top = 0;
	cnt = 0;
	for(i = 0; i < vnum; i++){
		node[i].ve = 0;
		if(node[i].innum == 0) stk[top++] = i;
	}
	while(top > 0){
		u = stk[--top];
		topo[cnt++] = u;
		for(i = 0; i < node[u].lnum; i++){
			v = node[u].to[i].dir;
			if(node[v].ve < node[u].ve + node[u].to[i].weight){
				node[v].ve = node[u].ve + node[u].to[i].weight;
			}
			if(--node[v].innum == 0) stk[top++] = v;
		}
		qsort(stk,top,sizeof(stk[0]),cmp2);
	}
	free(stk);
	return cnt == vnum;
}

void print_path(int top,int end){
	int u,v,i;
	u = path[top-1];
	if(u == end){
		printf("%s",node[path[0]].name);
		for(i = 1; i < top; i++){
			printf("-%s",node[path[i]].name);
		}
		printf("\n");
		return;
	}
	for(i = 0; i < node[u].lnum; i++){
		v = node[u].to[i].dir;
		if(node[u].ve + node[u].to[i].weight < node[v].ve) continue;
		if(node[v].ve == node[v].vl){
			path[top++] = v;
			print_path(top,end);
			top--;
		}
	}
}

void critical_path(){
	int i,j,u,v;
	if(!topo_sort()){
		printf("NO TOPOLOGICAL PATH\n");
		return;
	}
	for(i = 0; i < vnum; i++){
		node[i].vl = node[vnum-1].ve;
		if(i) printf("-");
		printf("%s",node[topo[i]].name);
	}
	printf("\n");
	for(i = vnum-2; i >= 0; i--){
		u = topo[i];
		for(j = 0; j < node[u].lnum; j++){
			v = node[u].to[j].dir;
			if(node[u].vl > node[v].vl - node[u].to[j].weight){
				node[u].vl = node[v].vl - node[u].to[j].weight;
			}
		}
	}
	path[0] = topo[0];
	print_path(1,topo[vnum-1]);
}

int main(){
	scanf("%d,%d",&vnum,&arcnum);
	create();
	critical_path();
	return 0;
}

