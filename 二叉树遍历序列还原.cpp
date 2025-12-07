#include <bits/stdc++.h>
using namespace std;   
typedef struct bitree{
	char value;
	bitree *leftree;
	bitree *righttree;
};
void build(string s1,string s2,bitree* &root){
	root=new bitree;
	int book;
	if(s1.empty()){
		root=NULL;
		return;
	}
	root->value=s2[s2.size()-1];
	if(s1==s2&&s1.size()==1){
		root->leftree=NULL;
		root->righttree=NULL;
		return;
	}
	string ss1l="",ss2l="",ss1r="",ss2r="";
	for(int i=0;i<s1.size();i++){
		if(s1[i]==root->value){
			book=i;
		}
	}
	for(int i=0;i<book;i++){
		ss1l+=s1[i];
		ss2l+=s2[i];
	}
	for(int i=book+1;i<s1.size();i++){
		ss1r+=s1[i];
		ss2r+=s2[i-1];
	}
	build(ss1l,ss2l,root->leftree);
	build(ss1r,ss2r,root->righttree);
}
void output(bitree* &root){
	queue<bitree*> q;
	if(root!=NULL) {
		q.push(root); 
	}
	while(!q.empty()){ 
		cout<<q.front()->value; 
		if(q.front()->leftree!=NULL) { 
			q.push(q.front()->leftree);
		}
		if (q.front()->righttree!= NULL) { 
			q.push(q.front()->righttree);
		}
	q.pop(); 
	}	
}
int main()     
{   
    bitree* root;
    string s1,s2;
	cin>>s1>>s2;
	build(s1,s2,root);
    output(root);  
    cout<<endl;
    return 0;     
}  