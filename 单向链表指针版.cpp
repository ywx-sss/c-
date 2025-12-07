#include<stdio.h>
#include<stdlib.h>
 
typedef struct Node {
	int value;
	struct Node* next;
}Node;
 
Node* head = NULL;
void charu(int x, int y)//插入
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Memory allocation failed.\n");//翻译过来是内存分配失败
		exit(1);
	}
	newNode->value = y;
	Node* p = head;
	while (p != NULL&&p->value !=x) {//如果不是空链表进入寻找x的位置
		p = p->next;
	}
	if (p->value != NULL) {//如果找到了
		newNode->next = p->next;
		p->next = newNode;
	}
	else {//如果没有找到
		printf("Element %d not found in the list.\n", x);//翻译过来是元素x未在列表中找到。
	}
}
 
int chaxun(int x)
{
	Node* p = head;
	while (p != NULL && p->value != x) //如果不是空链表进入寻找x的位置
		p = p->next;
	if (p != NULL && p->next != NULL) {//如果都没有超出链表长度的话就找到查询的数字了
		return p->next->value;
	}
	else return 0;
}
 
 
void shanchu(int x)
{
	Node* p = head;
	while (p != NULL && p->value != x) //如果不是空链表进入寻找x的位置
		p = p->next;
	if (p != NULL && p->next != NULL) {
		Node* q = p->next;
		p->next = q->next;//删除的精髓
		free(q);//空间释放
	}
	else  printf("Element %d or its successor is not found in the list.\n", x);//自己翻译吧
}
int main()
{
	head = (Node*)malloc(sizeof(Node));
	head->value = 1;//题目要求第一个为1
	head->next = NULL;//初始化
 
	int n;//操作次数
	scanf("%d", &n);//输入
	while (n--) {
		int m, x, y;//m为操作指令,可以用switch语句来实现
		scanf("%d%d", &m, &x);
		switch (m)
		{
		case 1://元素插入
			scanf("%d", &y);
			charu(x, y);
			break;//不要忘了
		case 2://元素查找
			printf("%d\n", chaxun(x));
			break;//不要忘了
		case 3://元素删除
			shanchu(x);
			break;//不要忘了
		default:printf("Invalid operation.\n");//翻译过来是无效操作。
		}
	}
	return 0;
}