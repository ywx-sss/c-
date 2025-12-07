#include <iostream>  
using namespace std;  
class sortnode{
	public: 
    	int data;  
    	struct node * next;  
	typedef sortnode NODE;  
	typedef sortnode * PNODE;  
	void outlist( PNODE );  
	void sortlist( PNODE, int);  
};  
int main( )  
{   int num=1;  
    sortnode:PNODE head;  
    head = new NODE;  
    head->next = NULL;  
    head->data = -1;  
  
    while ( num!=0 )  
    {   cin >> num;  
        if ( num!=0 )  
            sortnode.sortlist( head, num);  
    }  
    sortnode.outlist( head );  
    return 0;  
}  
  
void sortnode:outlist( PNODE head )  
{   PNODE p;  
    p = head->next;  
    while ( p != NULL )  
    {   cout << p->data << endl;  
        p = p->next;  
    }  
}  
  
/* This is an example for list. Please programme your code like it. 
sortlist( PNODE h, int num ) 
{   ... 
} 
*/  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  
  
void sortnode:sortlist(PNODE p,int num){  
    PNODE p1=p;  
    PNODE p2=p->next;   
    PNODE s=(PNODE)malloc(sizeof(NODE));  
    s->data=num;  
    while(p2&&p2->data<num)  
    {  
        p1=p2;  
        p2=p2->next;   
    }  
    if(!p2||(p2&&p2->data!=s->data)){  
        s->next=p2;  
        p1->next=s;    
    }  
}