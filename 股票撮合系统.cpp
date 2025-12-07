#include<stdio.h>   
#include<stdlib.h>   
#define length sizeof(struct node)   
typedef struct node   
{   
    int orderid;   
    int squenceid;   
    int quantity;   
    char type;   
    struct node *next;   
    float price;  
} Stack, *Order;   

int stockid, num;  
float money;   
char dealtype;   
int cal = 1;   
Order buy, sell, cur_buy, cur_sell, next_buy, next_sell, prev_buy, prev_sell,p,p1,q,q1;   

void treat1();   
void treat2();   
void treat3();   

int main()   
{   
    buy = (Order)malloc(length); buy->next = NULL;   
    sell = (Order)malloc(length); sell->next = NULL;   
    int whattodo;   
    while (1) {   
        scanf("%d", &whattodo);   
        if (whattodo == 0) break;   
        switch (whattodo) {   
            case 1: treat1(); break;   
            case 2: treat2(); break;   
            case 3: treat3(); break;   
        }   
    }   
    return 0;   
}   

void treat1()   
{   
    cur_buy = buy; cur_sell = sell; next_buy = cur_buy->next; next_sell = cur_sell->next;   
    scanf("%d %f %d %c", &stockid, &money, &num, &dealtype);   
    printf("orderid: %04d\n", cal++);   
    if (dealtype == 'b') {   
        while (next_sell != NULL) {   
            if (money >= next_sell->price) {   
                if (stockid == next_sell->squenceid) {   
                    if (num == next_sell->quantity) {   
                        printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n", (money + next_sell->price) / 2, num, cal - 1, next_sell->orderid);   
                        num = 0;   
                        cur_sell->next = next_sell->next;   
                        free(next_sell); next_sell = cur_sell->next; break;   
                    }   
                    else if (num < next_sell->quantity) {   
                        printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n", (money + next_sell->price) / 2, num, cal - 1, next_sell->orderid);   
                        next_sell->quantity -= num;   
                        num = 0;   
                        break;   
                    }   
                    else if (num > next_sell->quantity) {   
                        printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n", (money + next_sell->price) / 2, next_sell->quantity, cal - 1, next_sell->orderid);   
                        num -= next_sell->quantity;   
                        cur_sell->next = next_sell->next;   
                        free(next_sell);   
                        next_sell = cur_sell->next;   
                        continue;   
                    }   
                }   
                else {   
                    cur_sell = cur_sell->next; next_sell = cur_sell->next; continue;   
                }   
            }   
            else break;   
        }   
        if (num != 0) {   
            prev_buy = buy; cur_buy = prev_buy->next;   
            while (cur_buy) {   
                if (money > cur_buy->price) {   
                    Order new_order = (Order)malloc(length); new_order->orderid = cal - 1; new_order->price = money; new_order->quantity = num; new_order->squenceid = stockid; new_order->type = dealtype;   
                    prev_buy->next = new_order; new_order->next = cur_buy;   
                    break;   
                }   
                else {   
                    prev_buy = prev_buy->next; cur_buy = prev_buy->next;   
                }   
            }   
            if (cur_buy == NULL) {   
                Order new_order = (Order)malloc(length); new_order->orderid = cal - 1; new_order->price = money; new_order->quantity = num; new_order->squenceid = stockid; new_order->type = dealtype;   
                prev_buy->next = new_order; new_order->next = NULL;   
            }   
        }   
    }   
    if (dealtype == 's') {   
        while (next_buy != NULL) {   
            if (money <= next_buy->price) {   
                if (stockid == next_buy->squenceid) {   
                    if (num == next_buy->quantity) {   
                        printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n", (money + next_buy->price) / 2, num, cal - 1, next_buy->orderid);   
                        num = 0;   
                        cur_buy->next = next_buy->next;   
                        free(next_buy); next_buy = cur_buy->next; break;   
                    }   
                    else if (num < next_buy->quantity) {   
                        printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n", (money + next_buy->price) / 2, num, cal - 1, next_buy->orderid);   
                        next_buy->quantity -= num;   
                        num = 0;   
                        break;   
                    }   
                    else if (num > next_buy->quantity) {   
                        printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n", (money + next_buy->price) / 2, next_buy->quantity, cal - 1, next_buy->orderid);   
                        num -= next_buy->quantity;   
                        cur_buy->next = next_buy->next;   
                        free(next_buy);   
                        next_buy = cur_buy->next;   
                        continue;   
                    }   
                }   
                else {   
                    cur_buy = cur_buy->next; next_buy = cur_buy->next; continue;   
                }   
            }   
            else break;   
        }   
        if (num != 0) {   
            prev_sell = sell; cur_sell = prev_sell->next;   
            while (cur_sell) {   
                if (money < cur_sell->price) {   
                    Order new_order = (Order)malloc(length); new_order->orderid = cal - 1; new_order->price = money; new_order->quantity = num; new_order->squenceid = stockid; new_order->type = dealtype;   
                    prev_sell->next = new_order; new_order->next = cur_sell;   
                    break;   
                }   
                else {   
                    prev_sell = prev_sell->next; cur_sell = prev_sell->next;   
                }   
            }   
            if (cur_sell == NULL) {   
                Order new_order = (Order)malloc(length); new_order->orderid = cal - 1; new_order->price = money; new_order->quantity = num; new_order->squenceid = stockid; new_order->type = dealtype;   
                prev_sell->next = new_order; new_order->next = NULL;   
            }   
        }   
    }   
}   

void treat2()   
{   
    scanf("%d", &stockid);   
    p = buy; q = p->next; p1 = sell; q1 = p1->next;   
    printf("buy orders:\n");   
    while (q) {   
        if (q->squenceid == stockid)   
            printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", q->orderid, q->squenceid, q->price, q->quantity, q->type);   
        p = p->next; q = p->next;   
    }   
    printf("sell orders:\n");   
    while (q1) {   
        if (q1->squenceid == stockid)   
            printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", q1->orderid, q1->squenceid, q1->price, q1->quantity, q1->type);   
        p1 = p1->next; q1 = p1->next;   
    }   
}   

void treat3()   
{   
    int id;   
    int found_buy = 0, found_sell = 0;   
    scanf("%d", &id);   
    p = buy; q = p->next;   
    while (q && !found_buy) {   
        if (q->orderid == id) {   
            printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", q->orderid, q->squenceid, q->price, q->quantity, q->type);   
            p->next = q->next; free(q); found_buy = 1; break;   
        }   
        else {   
            p = p->next; q = p->next;   
        }   
    }   
    p1 = sell; q1 = p1->next;   
    while (q1 && !found_sell && !found_buy) {   
        if (q1->orderid == id) {   
            printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", q1->orderid, q1->squenceid, q1->price, q1->quantity, q1->type);   
            p1->next = q1->next; free(q1); found_sell = 1; break;   
        }   
        else {   
            p1 = p1->next; q1 = p1->next;   
        }   
    }   
    if (!found_buy && !found_sell) {   
        printf("not found\n");   
    }   
}
