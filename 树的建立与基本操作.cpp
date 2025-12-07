#include <bits/stdc++.h>
using namespace std;
typedef struct tree{
	char value='!';
	int leaf=0,deepth=0;
}tree;
int main() {
    int deep=-1,num=1,deepmax=-1;
    tree a[1005];
    int leaves[1005]={0},leefnum=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]=='(')deep++;
    	deepmax=max(deepmax,deep);
    	if(s[i]==',')continue;
    	if(s[i]>='a'&&s[i]<='z'){
    		a[num].value=s[i];
    		a[num].deepth=deep;
    		int sum=num;
    		while(sum--){
    			if(a[sum].deepth==a[num].deepth-1){
    				a[sum].leaf++;
    				break;
				}
			}
    		num++;
		}
		if(s[i]==')')deep--;
	}
	num=1;
	while(a[num].value!='!'){
	    leaves[a[num].leaf]++;
		leefnum=max(leefnum,a[num].leaf);
		for(int i=1;i<=a[num].deepth;i++){
			cout<<"    ";
		}
		cout<<a[num].value<<endl;
		num++;	
	}
	cout<<"Degree of tree: "<<leefnum<<endl;
	for(int i=0;i<=leefnum;i++){
		cout<<"Number of nodes of degree "<<i<<": "<<leaves[i]<<endl;
	}
    return 0;
}
