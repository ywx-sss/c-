#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Status;

typedef struct glnode{
    int tag;
    union{
        char atom;
        struct glnode *h;
    } u;
    struct glnode *t;
} *GList;

static void skipsp(const char *s, int *i){
    while(s[*i]==' '||s[*i]=='\t'||s[*i]=='\r')(*i)++;
}

static GList parse(const char *s, int *i);
static void print_elem(GList e);

static GList parselist(const char *s, int *i){
    (*i)++;
    skipsp(s,i);
    if(s[*i]==')'){
        (*i)++;
        return NULL;
    }
    GList p=(GList)malloc(sizeof(*p));
    p->tag=1;
    p->t=NULL;
    p->u.h=parse(s,i);
    GList q=p;
    skipsp(s,i);
    while(s[*i]==','){
        (*i)++;
        GList r=(GList)malloc(sizeof(*r));
        r->tag=1;
        r->t=NULL;
        r->u.h=parse(s,i);
        q->t=r;
        q=r;
        skipsp(s,i);
    }
    if(s[*i]==')')(*i)++;
    return p;
}

static GList parse(const char *s, int *i){
    skipsp(s,i);
    if(s[*i]=='(')return parselist(s,i);
    if(s[*i]>='a'&&s[*i]<='z'){
        GList p=(GList)malloc(sizeof(*p));
        p->tag=0;
        p->u.atom=s[*i];
        p->t=NULL;
        (*i)++;
        return p;
    }
    return NULL;
}

Status CreateGList(GList *L, char *S){
    int i=0;
    *L=parse(S,&i);
    return 1;
}

GList GetHead(GList L){
    if(!L||L->tag==0)return NULL;
    return L->u.h;
}

GList GetTail(GList L){
    if(!L||L->tag==0)return NULL;
    return L->t;
}

static void destroy(GList L){
    if(!L)return;
    if(L->tag==0){
        free(L);
        return;
    }
    destroy(L->u.h);
    destroy(L->t);
    free(L);
}

void DestroyGList(GList *L){
    destroy(*L);
    *L=NULL;
}

static void printg(GList L){
    if(!L){
        printf("()\n");
        return;
    }
    if(L->tag==0){
        printf("%c\n",L->u.atom);
        return;
    }
    print_elem(L);
    printf("\n");
}

static void print_elem(GList e){
    if(!e){
        printf("()");
        return;
    }
    if(e->tag==0){
        printf("%c",e->u.atom);
        return;
    }
    printf("(");
    GList p=e;
    int first=1;
    while(p){
        if(!first)printf(",");
        first=0;
        print_elem(p->u.h);
        p=p->t;
    }
    printf(")");
}

void PrintGList(GList L){
    printg(L);
}

int main(){
    char s[2048];
    if(!fgets(s,sizeof(s),stdin))return 0;
    size_t n=strlen(s);
    while(n>0&&(s[n-1]=='\n'||s[n-1]=='\r'))s[--n]=0;
    GList L=NULL;
    CreateGList(&L,s);
    printf("generic list: ");
    PrintGList(L);
    char line[128];
    while(L&&L->tag==1&&fgets(line,sizeof(line),stdin)){
        size_t m=strlen(line);
        while(m>0&&(line[m-1]=='\n'||line[m-1]=='\r'))line[--m]=0;
        if(m==0)continue;
        if(line[0]=='1'){
            GList nl=GetHead(L);
            printf("destroy tail\n");
            destroy(L->t);
            printf("free list node\n");
            free(L);
            L=nl;
            if(L==NULL){
                printf("generic list: ");
                printf("()\n");
                break;
            }
            printf("generic list: ");
            PrintGList(L);
        }else if(line[0]=='2'){
            GList nl=GetTail(L);
            printf("free head node\n");
            destroy(L->u.h);
            printf("free list node\n");
            free(L);
            L=nl;
            if(L==NULL){
                printf("generic list: ");
                printf("()\n");
                break;
            }
            printf("generic list: ");
            PrintGList(L);
        }
        if(!L||L->tag==0)break;
    }
    return 0;
}


