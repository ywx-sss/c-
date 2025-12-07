#include <stdio.h>
int num=0;
void jiaogu(int x){
	if(x==1||num==20)return;
	    num++;	
	if(x%2==1){
		printf("%d*3+1=%d\n",x,x*3+1);
		jiaogu(x*3+1);
	}
	if(x%2==0){
		printf("%d/2=%d\n",x,x/2);
		jiaogu(x/2);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	jiaogu(n);
	return 0;
}