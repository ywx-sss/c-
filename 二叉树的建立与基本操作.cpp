
#include <bits/stdc++.h>
using namespace std;
string s;
typedef struct Bitree{
	char data;
	Bitree* left;
	Bitree* right;
}Bitree;
void outtree(Bitree *&tree,int deepth){
	if(tree!=NULL){	
	    for(int i=1;i<=deepth*4;i++)cout<<" ";
	    cout<<tree->data<<endl;
     	outtree(tree->left,deepth+1);
	    outtree(tree->right,deepth+1);
	}
}
void create_bitree(Bitree *&tree) {
	static int i = -1;
	if (s[++i] != '#') {
		tree = new Bitree;
		tree->data = s[i];
		create_bitree(tree->left);
		create_bitree(tree->right);
	} 
	else {
		tree = NULL;
	}
}
void preorder(Bitree *&tree){
	if(tree!=NULL){	
	    cout<<tree->data;
     	preorder(tree->left);
	    preorder(tree->right);
	}
}
void inorder(Bitree *&tree){
	if(tree!=NULL){	    
     	inorder(tree->left);
		cout<<tree->data;
	    inorder(tree->right);
	}
}
void postorder(Bitree *&tree){
	if(tree!=NULL){	
     	postorder(tree->left);
	    postorder(tree->right);
	    cout<<tree->data;
	}
}
int checkleef(Bitree *&tree,int &leef){
	
	if(tree!=NULL){
	    if(tree->left==NULL&&tree->right==NULL){	
     		leef++;
	    }
		checkleef(tree->left,leef);
		checkleef(tree->right,leef); 
	}
	return leef;
}
void swapbitree(Bitree *&tree){
	if(tree!=NULL){
		if(tree->left!=NULL||tree->right!=NULL) {
			Bitree* tmp;        
        	tmp=tree->left;
        	tree->left=tree->right;
        	tree->right=tmp;
    	}
    	swapbitree(tree->left);
    	swapbitree(tree->right);
	}
}
int main() {
	cin>>s;
	int leef=0;
	Bitree* root;
	create_bitree(root);
	cout<<"BiTree"<<endl;
	outtree(root,0);
	cout<<"pre_sequence  : ";
	preorder(root);cout<<endl;
	cout<<"in_sequence   : ";
	inorder(root);cout<<endl;
	cout<<"post_sequence : ";
	postorder(root);cout<<endl;
	cout<<"Number of leaf: "<<checkleef(root,leef)<<endl;
	swapbitree(root);
	cout<<"BiTree swapped"<<endl;
	outtree(root,0);
	cout<<"pre_sequence  : ";
	preorder(root);cout<<endl;
	cout<<"in_sequence   : ";
	inorder(root);cout<<endl;
	cout<<"post_sequence : ";
	postorder(root);cout<<endl;
	return 0;
}