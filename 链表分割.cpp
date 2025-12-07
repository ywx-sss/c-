#include <iostream>  
using namespace std;  
  
class List  
{  
        struct Node {  
            int data;  
            Node *next;  
            Node()  
            {  
                data = -1;  
                next = NULL;  
            }  
            Node(int x, Node *p=NULL)  
            {  
                data = x;  
                next = p;  
            }  
        };  
    protected:  
        Node * first;  
    public:  
        List()  
        {  
            first = new Node;  
        }  
        ~List()  
        {  
            freeList();  
        }  
        void freeList();  
        void append(const int num);  
        void output();  
        void split(List& A, List& B);  
};  
  
void List::freeList()  
{  
    Node * del;  
    while ( first->next != NULL ) {  
        del = first->next;  
        first->next = del->next;  
        delete del;  
    }  
}  
  
void List::append(int num)  
{  
    Node *last = first;  
    while ( last->next!=NULL ) {  
        last = last->next;  
    }  
    last->next = new Node( num );  
}  
  
void List::output()  
{  
    Node *p = first->next;  
    while ( p!=NULL ) {  
        cout << p->data << ",";  
        p = p->next;  
    }  
    cout << endl;  
}  
void List::split(List& A, List& B){
	Node *p=first->next;
	while ( p!=NULL ) {  
        if(p->data%2==1){
        	A.append(p->data);
		}  
		else{
			B.append(p->data);
		}
		p = p->next;
    }   
}  
int main(int argc, char** argv)  
{  
    List L, A, B;  
    int num;  
    cin >> num;  
    while ( num != -1 ) {  
        L.append(num);  
        cin >> num;  
    }  
    cout << "L=";  
    L.output();  
    L.split(A, B);  
    cout << "A=";  
    A.output();  
    cout << "B=";  
    B.output();  
    cout << "L=";  
    L.output();  
    L.~List();  
    A.~List();  
    B.~List();  
    return 0;  
}