#include <iostream>  
using namespace std;  
  
class Joseph  
{  
    private:  
        struct node {  
            int data;  
            node * next;  
  
            node(int d, node *p=NULL) : data(d), next(p) {  }  
        };  
        node * head;  
    public:  
        Joseph(int n);  //构造函数  
        void outJoseph();           //输出环  
        void simulate(int m, int k);    //对约瑟夫环中的结点进行计数，以m为步长将结点依次出环  
        ~Joseph();              //析构函数  
};  
  
Joseph::Joseph(int n)       //构造函数  
{  
    node *tail;  
    //建立有表头结点的环型链表  
    head = tail = new node(-1); //创建第一个结点，head指向表头，p指向表尾  
    for ( int i=0; i<n; ++i ) {  
        tail->next = new node(i);  
        tail = tail->next;  
    }  
    tail->next = head;               //头尾相连  
}  
  
Joseph::~Joseph()  
{  
    node *p;  
    if (head==NULL) return;  
    while (head->next!=head) {  
        p = head->next;  
        head->next = p->next;  
        delete p;  
    }  
    delete head;  
}    
void Joseph::outJoseph()  
{  
    node *p;  
    p = head;  
    while ( p->next!=head ) {  
        p = p->next;  
        cout << p->data << ",";  
    }  
    cout << endl;  
}  
void Joseph::simulate(int m, int k) {
    node *p = head->next; // 指向第一个实际的节点（编号0）
    node *prev = head; // 指向当前节点的前一个节点

    // 初始时，哑节点的next已经指向第一个实际节点，不需要额外操作

    while (k > 0) {
        // 报数到m-1，找到第m个节点的前一个节点
        for (int count = 1; count < m; ++count) {
            prev = p;
            p = p->next;
        }

        // 输出出列节点的数据，但跳过头节点的-1
        if (p != head) {
            cout << p->data << " ";
        }

        // 从环中移除第m个节点
        prev->next = p->next;

        // 如果移除的是尾节点，更新哑节点的next指向新的尾节点
        if (p->next == head->next) {
            head->next = prev;
        }

        // 释放被移除节点的内存
        delete p;

        // 更新p为下一个要开始报数的节点，即prev的下一个节点
        p = prev->next;

        // 减少出列计数
        k--;
    }
    cout << endl;
}
int main(int argc, char** argv)  
{  
    int n, m, k;    //n个  
    cin >> n >> m >> k;  
    Joseph h(n);  
//  h.outJoseph();  
    h.simulate(m, k);  
    h.outJoseph(); 
    return 0;  
} 