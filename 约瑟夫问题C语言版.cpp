#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} loopnode;

void create(loopnode** loop, int n) {
    *loop = (loopnode*)malloc(sizeof(loopnode));
    (*loop)->link = *loop;
    
    loopnode* r = *loop;
    for(int i = 1; i <= n; i++) {
        loopnode* p = (loopnode*)malloc(sizeof(loopnode));
        p->data = i;
        p->link = r->link;
        r->link = p;
        r = p;
    }
}

void Jose(loopnode* loop, int k, int m, int n) {
    loopnode* p = loop->link;
    loopnode* pre = loop;
    
    for(int i = 1; i < k; i++) {
        pre = p;
        p = p->link;
        if(p == loop) {
            pre = p;
            p = p->link;
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < m; j++) {
            pre = p;
            p = p->link;
            if(p == loop) {
                pre = p;
                p = p->link;
            }
        }
        printf("%d", p->data);
        if(i != n&&i % 10 != 0) printf(" ");
        if(i % 10 == 0 || i == n) printf("\n");
        pre->link = p->link;
        free(p);
        p = pre->link;
        if(p == loop && i != n) {
            pre = p;
            p = p->link;
        }
    }
}

int main() {
    int n, k, m;
    scanf("%d,%d,%d", &n, &k, &m);
    
    if(n < 1 || k < 1 || m < 1) {
        printf("n,m,k must bigger than 0.\n");
        return 0;
    }
    if(k > n) {
        printf("k should not bigger than n.\n");
        return 0;
    }
    
    loopnode* loop = NULL;
    create(&loop, n);
    Jose(loop, k, m, n);
    return 0;
}