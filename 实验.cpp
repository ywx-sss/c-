#include <stdio.h>
int yuefen(int shang,int xia){
	int gy,num=1,q=shang>xia?shang:xia;
	for(int i=1;i<=q;i++){
		if(shang%i==0&&xia%i==0){
			num=i;
		}
	}
	return num;
}
int main(){
    int a,b,c,d,shang,shang_,xia,xia_;
    char s1,s2,fu;
    scanf("%d%c%d %c %d%c%d",&a,&s1,&b,&fu,&c,&s2,&d);
    if(fu=='+'){
    	shang=a*d+b*c;
    	xia=b*d;
	}
	if(fu=='-'){
    	shang=a*d-b*c;
    	xia=b*d;
	}
	if(fu=='*'){
    	shang=a*c;
    	xia=b*d;
	}
	if(fu=='/'){
    	shang=a*d;
    	xia=b*c;
	}
	shang_=shang;xia_=xia;
    shang_/=yuefen(shang,xia);
    xia_/=yuefen(shang,xia);
    if(xia_!=1)printf("%d/%d %c %d/%d = %d/%d\n",a,b,fu,c,d,shang_,xia_);
    else printf("%d/%d %c %d/%d = %d\n",a,b,fu,c,d,shang_);
	return 0;
}