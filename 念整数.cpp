#include <stdio.h>
int main(){
	int n,sum[51]={0},i=1;
	char *a[10]={(char*)"ling",(char*)"yi",(char*)"er",(char*)"san",(char*)"si",(char*)"wu",(char*)"liu",(char*)"qi",(char*)"ba",(char*)"jiu"};
	scanf("%d",&n);
	if(n<0){
	    printf("fu ");n=-n;
    }
    if(n==0){
	    printf("ling\n");
	    return 0;
    }
    while(n!=0){
    	sum[i]=n%10;
    	n/=10;
    	i++;
	}
	for(int j=i-1;j>1;j--){
		printf("%s ",a[sum[j]]);
	}
	printf("%s\n",a[sum[1]]);
	return 0;
}