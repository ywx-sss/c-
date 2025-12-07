#include <stdio.h> 
int main() 
{ 
    char c,fu;
    int maxx=-1,minn=999999999;
    while(1){
    	scanf("%c",&c);
    	if(c=='=')break;
    	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='%'){
    	    fu=c;
    	    scanf(",");
    	    continue;
		}
    	if(c-48>maxx)maxx=c-48;
    	if(c-48<minn)minn=c-48;
    	scanf(",");
	}
	switch(fu){
		case '+':{
		    printf("%d%c%d=%d\n",maxx,fu,minn,maxx+minn);
		    break;
		}
		case '-':{
		    printf("%d%c%d=%d\n",maxx,fu,minn,maxx-minn);
		    break;
		}
		case '*':{
		    printf("%d%c%d=%d\n",maxx,fu,minn,maxx*minn);
		    break;
		}
		case '/':{
			if(minn!=0)
			    printf("%d%c%d=%d\n",maxx,fu,minn,maxx/minn);
			else 
			    printf("Error!");
		    break;
		}
		case '%':{
		    printf("%d%c%d=%d\n",maxx,fu,minn,maxx%minn);	
		    break;
		}
	}
    return 0; 
}  