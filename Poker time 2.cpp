#include<bits/stdc++.h>
using namespace std;
int flag=0,flagA=1,flagB=1;
typedef struct{
	int color=-1,num=-1;
}poker;
bool cmp(poker a,poker b) {
    if (a.num==b.num) return a.color < b.color;	
    return a.num > b.num;  					
}

int check(poker a1,poker a2,poker a3) {
    if(a1.color==a2.color&&a2.color==a3.color&&a1.num-1==a2.num&&a2.num-1==a3.num)return 5;
	if(a1.num==a2.num&&a2.num==a3.num)return 4;
	if((abs(a2.num-a3.num)==2&&(a2.num+a3.num)==a1.num*2)||(abs(a1.num-a3.num)==2&&(a1.num+a3.num)==a2.num*2)||(abs(a1.num-a2.num)==2&&(a1.num+a2.num)==a3.num*2))return 3;
	if(a1.num==a2.num||a1.num==a3.num||a2.num==a3.num)return 2;
	return 1;				
}
int cmp2(poker a,poker b) {	
		if(a.num>b.num)return 1;
    	if(a.num==b.num) {
	    	if(a.color<b.color)return 1;
			if(a.color==b.color)return 0;
			if(a.color>b.color)return -1;
		}
    	if(a.num<b.num)return -1;					
}
int find(poker a[4],poker b[4],int flag){
	if(flag==5){
		if(a[1].num>b[1].num)return 1;
		if(a[1].num==b[1].num){
			if(a[1].color<b[1].color)return 1;
			if(a[1].color==b[1].color)return 0;
			if(a[1].color>b[1].color)return -1;
		}
		if(a[1].num<b[1].num)return -1;
	}
	if(flag==4){
		if(a[1].num>b[1].num)return 1;
		if(a[1].num<b[1].num)return -1;
		if(a[1].num==b[1].num){
			for(int i=1;i<=3;i++){
				if(cmp2(a[i],b[i])==1){
					return 1;
				}
				if(cmp2(a[i],b[i])==-1){
					return -1;
				}
			}
		}
	}
	if(flag==3){
		if(min(a[1].num,min(a[2].num,a[3].num))>min(b[1].num,min(b[2].num,b[3].num)))return 1;
		if(min(a[1].num,min(a[2].num,a[3].num))<min(b[1].num,min(b[2].num,b[3].num)))return -1;
		if(min(a[1].num,min(a[2].num,a[3].num))==min(b[1].num,min(b[2].num,b[3].num))){
			if(a[1].color+a[2].color+a[3].color<b[1].color+b[2].color+b[3].color)return 1;
			if(a[1].color+a[2].color+a[3].color==b[1].color+b[2].color+b[3].color)return 0;
			if(a[1].color+a[2].color+a[3].color>b[1].color+b[2].color+b[3].color)return -1;
		}	
	}
	if(flag==2){
		int numansa,color1a,color2a,numansb,color1b,color2b;
		if(a[1].num==a[2].num)numansa=a[1].num,color1a=a[1].color,color2a=a[2].color;
		if(a[2].num==a[3].num)numansa=a[2].num,color1a=a[2].color,color2a=a[3].color;
		if(a[1].num==a[3].num)numansa=a[1].num,color1a=a[1].color,color2a=a[3].color;
		if(b[1].num==b[2].num)numansb=b[1].num,color1b=b[1].color,color2b=b[2].color;
		if(b[2].num==b[3].num)numansb=b[2].num,color1b=b[2].color,color2b=b[3].color;
		if(b[1].num==b[3].num)numansb=b[1].num,color1b=b[1].color,color2b=b[3].color;
		/*cout<<numansa<<endl;
		cout<<numansb<<endl;
		cout<<color1a<<" "<<color2a<<endl;
		cout<<color1b<<" "<<color2b<<endl;*/
		if(numansa>numansb)return 1;
		if(numansa<numansb)return -1;
		if(numansa==numansb){
			if(color1a+color2a<color1b+color2b)return 1;
			if(color1a+color2a==color1b+color2b){
				for(int i=1;i<=3;i++){
				if(cmp2(a[i],b[i])==1){
					return 1;
				}
				if(cmp2(a[i],b[i])==-1){
					return -1;
				}
			}
			}
			if(color1a+color2a>color1b+color2b)return -1;
		}
	}
}
int main() {
    string t,biao[13]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    char c[4]={'H','S','D','C'};
    poker a[4],b[4];
    for(int i=1;i<=3;i++){
    	cin>>t;
    	for(int j=0;j<=3;j++){
    		if(c[j]==t[0])a[i].color=j;
		}
		t.erase(0, 1);
		for(int j=0;j<=12;j++){
    		if(biao[j]==t)a[i].num=j;
		}
		if(a[i].color==-1||a[i].num==-1){
			cout<<"Input Error!"<<endl;
			return 0;
		}
	}  
	for(int i=1;i<=3;i++){
    	cin>>t;
    	for(int j=0;j<=3;j++){
    		if(c[j]==t[0])b[i].color=j;
		}
		t.erase(0, 1);
		for(int j=0;j<=12;j++){
    		if(biao[j]==t)b[i].num=j;
		}
		if(b[i].color==-1||b[i].num==-1){
			cout<<"Input Error!"<<endl;
			return 0;
		}
	} 
	for(int i=1;i<=2;i++){
		for(int j=i+1;j<=3;j++){
			if(cmp2(a[i],a[j])==0||cmp2(b[i],b[j])==0){
				cout<<"Input Error!"<<endl;
			    return 0;
			}
		}
	}
	sort(a+1,a+4,cmp);
	sort(b+1,b+4,cmp);
	flagA=check(a[1],a[2],a[3]);
	flagB=check(b[1],b[2],b[3]);
	if(flagA>flagB)flag=1;
	if(flagA<flagB)flag=-1;
	if(flagB==flagA){
		if(flagA==1){
			for(int i=1;i<=3;i++){
				if(cmp2(a[i],b[i])==1){
					flag=1;break;
				}
				if(cmp2(a[i],b[i])==-1){
					flag=-1;break;
				}
			}
		}
		else{
			flag=find(a,b,flagA);
		}
	}
	if(flag==1)cout<<"Winner is A!"<<endl;
	if(flag==0)cout<<"Draw!"<<endl;
	if(flag==-1)cout<<"Winner is B!"<<endl;
	cout<<"A:";
	for(int i=1;i<=3;i++){
		cout<<" "<<c[a[i].color]<<biao[a[i].num];
	}
	cout<<endl;
	cout<<"B:";
	for(int i=1;i<=3;i++){
		cout<<" "<<c[b[i].color]<<biao[b[i].num];
	}
	cout<<endl;
} 