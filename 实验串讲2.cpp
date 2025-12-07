#include <stdio.h>
int main(){
	int a=3, b=2, m=2, n=2;
	(m=15>a>b)&&++n;
    printf("%d %d\n",m,n);
	return 0;
}
