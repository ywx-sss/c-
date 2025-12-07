#include <bits/stdc++.h>
using namespace std;
typedef struct lian{
	int data;
	lian *next;
}lian;//定义一个类似于递归的链表（精髓）
int main(){
   lian *head=NULL,*p,*q,*t;
   int n,a;
   cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a;
    	p=(lian*)malloc(sizeof(lian));//申请动态存储空间
    	p->data=a;
    	p->next=NULL;
    	if(head==NULL){
    		head=p;
		}
		else q->next=p;
		q=p;
	}	
	cin>>a;t=head;
	while(t!=NULL){
		if(t->next==NULL||t->next->data>a){//插入数据
			p=(lian*)malloc(sizeof(lian));
			p->data=a;
			p->next=t->next;
			t->next=p;
			break;
		}
	}t=head;
	while(t!=NULL){
		cout<<t->data<<" ";
		t=t->next;
	}
	return 0;
}