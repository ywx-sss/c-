#include <bits/stdc++.h>
using namespace std;
string expression;
struct stacker{
	int num[1000];
	int point;
}stacker;

int kind(char ch){
	if(ch>='0'&&ch<='9')return 1;
	else if(ch=='+')return 2;
	else if(ch=='-')return 3;
	else if(ch=='*')return 4;
	else if(ch=='/')return 5;
	else return 0;
}
int main(){
	stacker.point=0;
	getline(cin,expression);
	int len=expression.size();
	for(int i=0;i<len;i++){
		if(kind(expression[i])==1){
			int digit=0,ans=0,j;
			for(j=i;kind(expression[j])==1;j++){
				ans=ans*10+expression[j]-'0';
			}
			i=j;
			stacker.num[stacker.point]=ans;
			stacker.point++;
			continue;
		}else if(kind(expression[i])==2){
			stacker.num[stacker.point-2]=stacker.num[stacker.point-2]+stacker.num[stacker.point-1];
			stacker.point--;
		}else if(kind(expression[i])==3){
			if(kind(expression[i+1])==1){
				i++;
				int digit=0,ans=0,j;
				for(j=i;kind(expression[j])==1;j++){
					ans=ans*10+expression[j]-'0';
				}
				i=j;
				stacker.num[stacker.point]=-ans;
				stacker.point++;
				continue;
			}
			stacker.num[stacker.point-2]=stacker.num[stacker.point-2]-stacker.num[stacker.point-1];
			stacker.point--;
		}else if(kind(expression[i])==4){
			stacker.num[stacker.point-2]=stacker.num[stacker.point-2]*stacker.num[stacker.point-1];
			stacker.point--;
		}else if(kind(expression[i])==5){
			stacker.num[stacker.point-2]=stacker.num[stacker.point-2]/stacker.num[stacker.point-1];
			stacker.point--;
		}
	}
	cout<<stacker.num[0]<<endl;
	return 0;
}