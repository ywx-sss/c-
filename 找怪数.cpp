#include<stdio.h>
int main()
{
	int num1,num2,a1,a2,a3,a4,ans=0;
	while(true){
	    scanf("%d %d",&num1,&num2);
		if(num1==0||num2==0)
		    break;
        if(num1<1000||num2<1000||num1>9999||num2>9999||num1>num2){
		    printf("Error\n");	
		    continue;
		}
		for(int k=num1;k<=num2;k++){
			if(k%2==1)
			    continue;
			int i=k,ansnum=k;
			a1=i%10;
			i/=10;a2=i%10;
			i/=10;a3=i%10;
			i/=10;a4=i%10;
			if(a1!=a2&&a1!=a3&&a1!=a4&&a2!=a3&&a2!=a4&&a3!=a4){
	    	    printf("%d ",ansnum);
	    	    ans++;
		    }
		}
	    printf("\ncounter=%d\n",ans);
	    ans=0;
	}
    return 0;
}