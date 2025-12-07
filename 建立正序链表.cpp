#include <iostream>  
using namespace std;  
struct node  
{   int  data;  
    struct node * next;  
};  
typedef struct node NODE;  
typedef struct node * PNODE;  
void outlist( PNODE );  
int ins_list( PNODE, int );  
int main( )  
{   int num=1;  
    PNODE head;  
  
    head = new NODE;  
    head->next = NULL;  
    head->data = -1;  
  
    while ( num!=0 )  
    {   cin >> num;  
        if ( num!=0 )  
            ins_list( head, num);  
    }  
    outlist( head );  
    return 0;  
}  
  
void outlist( PNODE head )  
{   PNODE p;  
    p = head->next;  
    while ( p != NULL )  
    {   cout << p->data << endl;;  
        p = p->next;  
    }  
}  
int ins_list( PNODE h, int num ) 
{ 
    PNODE p;
    PNODE s=new NODE;
    s->data=num;
    p=h;
    while(p->next!=NULL){
    	p=p->next;
	}
	p->next=s;
	s->next=NULL;
	return 0;
} 
