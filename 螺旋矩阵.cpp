#include <stdio.h>
int main()
{
    int n,hang=1,lie=1,num=1,flag=1;
    scanf("%d", &n);
    int a[n+1][n+1]={0};
    while(1){
	    if(a[hang+1][lie]!=0&&a[hang-1][lie]!=0&&a[hang][lie+1]!=0&&a[hang][lie-1]!=0){
	    	a[hang][lie]=num;
		    break;	
		}
    	a[hang][lie]=num;	
    	if(flag==1)lie++;
        if(flag==2)lie--;
		if(flag==3)hang++;
		if(flag==4)hang--;
		num++;
		printf("%d %d %d\n",hang,lie,flag);
		if((flag==1&&lie==n)||(a[hang][lie+1]!=0&&flag==1)){
		    flag=3;
		    continue;
		}
        if((flag==2&&lie==1)||(a[hang][lie-1]!=0&&flag==2)){
		    flag=4;
		    continue;
		}
        if((flag==3&&hang==n)||(a[hang+1][lie]!=0&&flag==3)){
		    flag=2;
		    continue;
		}
        if((flag==4&&hang==1)||(a[hang-1][lie]!=0&&flag==4)){
		    flag=1;
		    continue;
		} 	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
    return 0;
}
