#include<iostream>
using namespace std;
struct node
{   int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node *PNODE;
void outlist( PNODE);
void sortlist( PNODE, int);
int main()
{       int num=1;  
    PNODE head;  
    head = new NODE;  
    head->next = NULL;  
    head->data = -1;  
  
    while ( num!=0 )  
    {   cin >> num;  
        if ( num!=0 )  
            sortlist(head, num);  
    }  
    outlist( head );  
    return 0;  
}  
  
void outlist( PNODE head )  
{   PNODE p;  
    p=head->next;  
    while ( p != NULL )  
    {
	    cout<<p->data<<endl;  
        p=p->next;
    }  
}
void sortlist( PNODE h, int num )
{    
    h=h->next;
    while(h->data<num){
    	h=h->next;
	}
	if(h->data==num)return;
	else {
		PNODE p;
		p->data=num;
		p->next=h->next;
		h->next=p;
		return;
	}
} 