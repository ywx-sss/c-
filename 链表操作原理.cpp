#include <stdio.h>
#include <stdlib.h>

	typedef struct node {
		int value;
		struct node *next;
	} NODE;
	typedef struct head {
		int count;
		struct node *next;
        struct node *tail;
	} HEAD;
int createLink(HEAD *head,int m);
int createReverseLink(HEAD *head,int m);
int output(HEAD *head);

NODE *Linkfind(HEAD *head, int value);
int LinkDelete(HEAD *head , int value);

int main(int argc, char *argv[]) {
	
	HEAD *head = (HEAD *) malloc(sizeof(HEAD));
	head->count = 0;
	head->next = NULL;
	head->tail = NULL;
	
	int m;
	scanf("%d",&m);
	
//	createLink(head,m);
	createReverseLink(head,m);
	output(head);
//	Linkfind(head,200);
	LinkDelete(head,20);
	output(head);
	LinkDelete(head,50);
	output(head);
	LinkDelete(head,10);
	output(head);
	LinkDelete(head,30);
	output(head);
	LinkDelete(head,300);
	output(head);
	LinkDelete(head,40);
	output(head);
	
	return 0;
}

int createLink(HEAD *head,int m){
	
	NODE *p;
	for(int i=0;i<m;i++) {
		p = (NODE *)malloc(sizeof(NODE));
		scanf("%d",&p->value);
		p->next = NULL;
		
		if (head->next == NULL) {
			head->next = p;
			head->tail = p;
		} else {
			head->tail->next = p;
			head->tail = p;
		}
		head->count++;
	}
	return 0;
}
int createReverseLink(HEAD *head,int m){
	NODE *p;
	for(int i=0;i<m;i++) {
		p = (NODE *)malloc(sizeof(NODE));
		scanf("%d",&p->value);
		p->next = head->next;
		head->next = p;
		head->count++;
	}
	return 0;
}
int output(HEAD *head){
	printf("----------------------------------\n");
	printf("%d\n",head->count);
	NODE *p = head->next;
	while( p!=NULL) {
		printf("%d\n",p->value);
		p= p->next;
	}
	return 0;
}


NODE *Linkfind(HEAD *head, int value){
	
	NODE *p = head->next;
	while (p!=NULL && p->value != value) {
		p=p->next;
	}
	if (p==NULL) {
		printf("Not Found\n");
	} else {
		printf("Found:%d\n",p->value);
	}
	return  0;
}
int LinkDelete(HEAD *head , int value){
	
	NODE *p = head->next;
	if (p!=NULL && p->value == value) {
		head->next = p->next;
		free(p);
		return 0;
	}
	
	while(p->next!=NULL && p->next->value != value ) {
		p = p->next;
	}
	
	if (p->next == NULL) {
		printf("Not Found\n");
		return 0;
	} else {
		NODE *t = p->next;
		p->next = t->next;
		free(t);
	}
	
	return  0;
	
	
}