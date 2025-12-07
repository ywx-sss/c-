#include <stdio.h>  
#include <stdlib.h>  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
NODE * find( NODE * , int * );  
void outputring( NODE * );  
void change( int , int , NODE * );  
void outputring( NODE * pring )  
{   NODE * p;  
    p = pring;  
    if ( p == NULL )  
        printf("NULL");  
    else  
        do  {   printf("%d", p->data);  
            p = p->next;  
        } while ( p != pring );  
    printf("\n");  
    return;  
}  
  
int main()  
{   int n, m;  
    NODE * head, * pring;  
  
    scanf("%d%d", &n, &m);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
  
    change( n, m, head );  
    pring = find( head, &n );  
    printf("ring=%d\n", n);  
    outputring( pring );  
  
    return 0;  
}  

void change(int n, int m, NODE *head)
{
    NODE **a;
    NODE *p = head;
    a = (NODE **) malloc(sizeof(NODE *) * m);
    for (int k = 0; k < m; k++)
        a[k] = NULL;
    while (n != 0)
    {   
        if (n * 10 % m == 0)
        {
            p->next = (NODE *) malloc(sizeof(NODE));

            p->next->data = n * 10 / m;
            p->next->next = NULL;

            n = 0;
        }
        else
        {
            if (a[n] == NULL)
            {
                a[n] = p->next = (NODE *) malloc(sizeof(NODE));

                p->next->data = n * 10 / m;
                n = n * 10 % m;
                p = p->next;
            }
            else
            {
                p->next = a[n];
                n = 0;
            }
        }
    }
}
NODE *find(NODE *head, int *num) 
{
    NODE *s = head->next, *e = head->next;
    
    while (e != NULL && e->next != NULL) {
        s = s->next;
        e = e->next->next;
        if (s == e)
            break;
    }

    if (e == NULL || e->next == NULL) {
        *num = 0;
        return NULL;
    }

    int ring = 1;
    e = e->next;
    while (e != s) {
        e = e->next;
        ring++;
    }

    s = head->next;
    e = head->next;
    for (int i = 0; i < ring; i++)
        e = e->next;
    
    while (s != e) {
        s = s->next;
        e = e->next;
    }

    *num = ring;
    return s;
}