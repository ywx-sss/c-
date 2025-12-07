#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	double x1,x2,der;
	if(a==0&&b==0){
		printf("Input error!\n");
	}
	if(a==0&&b!=0){	
	    if(c==0)printf("x=%.6f\n",c);
	    else	printf("x=%.6f\n",-c/b);
	}
	if(a!=0){
	    der=b*b-4*a*c;
	    if(der>0){
		    printf("x1=%.6f\n",((-b)+sqrt(der))/(2*a));
		    printf("x2=%.6f\n",((-b)-sqrt(der))/(2*a));
	    }
	    if(der==0){
		    printf("x1=x2=%.6f\n",(-b)/(2*a));
	    }
	    if(der<0){
		    double q,s;
		    q=sqrt(-der);
		    s=(-b)/(2*a);
		    if(s==0){
			    printf("x1=%.6fi\n",q/(2*a));
		        printf("x2=-%.6fi\n",q/(2*a));
	 	    }
		    else{
			    printf("x1=%.6f+%.6fi\n",s,q/(2*a));
		        printf("x2=%.6f-%.6fi\n",s,q/(2*a));
		    }
	    }
    }
	return 0;
}