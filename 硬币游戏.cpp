#include <stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	if(a%8!=0)printf("No change.\n");
	else printf("%d,%d,%d\n",50*(a/8),60*(a/8),45*(a/8));
	return 0;
}