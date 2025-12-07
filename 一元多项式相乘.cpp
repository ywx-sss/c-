#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{   int    coef, exp;  
    struct node  *next;  
} NODE;  
  
void multiplication( NODE *, NODE * , NODE * );  
void input( NODE * );  
void output( NODE * );  
  
void input( NODE * head )  
{   int flag, sign, sum, x;  
    char c;  
  
    NODE * p = head;  
  
    while ( (c=getchar()) !='\n' )  
    {  
        if ( c == '<' )  
        {    sum = 0;  
             sign = 1;  
             flag = 1;  
        }  
        else if ( c =='-' )  
             sign = -1;  
        else if( c >='0'&& c <='9' )  
        {    sum = sum*10 + c - '0';  
        }  
        else if ( c == ',' )  
        {    if ( flag == 1 )  
             {    x = sign * sum;  
                  sum = 0;  
                  flag = 2;  
          sign = 1;  
             }  
        }  
        else if ( c == '>' )  
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );  
             p->next->coef = x;  
             p->next->exp  = sign * sum;  
             p = p->next;  
             p->next = NULL;  
             flag = 0;  
        }  
    }  
}  
  
void output( NODE * head )  
{  
    while ( head->next != NULL )  
    {   head = head->next;  
        printf("<%d,%d>,", head->coef, head->exp );  
    }  
    printf("\n");  
}  

void multiplication(NODE *head1, NODE *head2, NODE *head3) {
    NODE *p1 = head1->next;
    while (p1 != NULL) {
        NODE *p2 = head2->next;
        while (p2 != NULL) {
            int coef = p1->coef * p2->coef, exp = p1->exp + p2->exp;
            if (coef == 0) {
                p2 = p2->next;
                continue;
            }
            NODE *p = head3;
            while (p->next != NULL && p->next->exp > exp) {
                p = p->next;
            }
            if (p->next != NULL && p->next->exp == exp) {
                p->next->coef += coef;
                if (p->next->coef == 0) {
                    NODE *temp = p->next;
                    p->next = temp->next;
                    free(temp);
                }
            } else {
                NODE *s = (NODE *)malloc(sizeof(NODE));
                s->coef = coef;
                s->exp = exp;
                s->next = p->next;
                p->next = s;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    if (head3->next == NULL) {
        NODE *s = (NODE *)malloc(sizeof(NODE));
        s->coef = 0;
        s->exp = 0;
        s->next = NULL;
        head3->next = s;
    }
}
int main()  
{   NODE * head1, * head2, * head3;  
  
    head1 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head1 );  
  
    head2 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head2 );  
  
    head3 = ( NODE * ) malloc( sizeof(NODE) );  
    head3->next = NULL;  
    multiplication( head1, head2, head3 );  
  
    output( head3 );  
    return 0;  
}