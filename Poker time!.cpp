#include<bits/stdc++.h>
using namespace std;
int flag=0;
typedef struct{
	int color=-1,num=-1;
}poker;
bool cmp(poker a,poker b) {
    if (a.color==b.color) return a.num > b.num;	
    return a.color < b.color;  					
}
int cmp2(poker a,poker b) {
	if (a.color>b.color)return 1;
    if (a.color==b.color) {
	    if(a.num>b.num)return 1;
		if(a.num==b.num)return 0;
		if(a.num<b.num)return -1;
	}
    if (a.color<b.color)return -1;					
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
	for(int i=1;i<=3;i++){
		if(cmp2(a[i],b[i])==1){
			flag=1;break;
		}
		if(cmp2(a[i],b[i])==-1){
			flag=-1;break;
		}
	}
	if(flag==1)cout<<"Winner is A!"<<endl;
	if(flag==0)cout<<"Winner is X!"<<endl;
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