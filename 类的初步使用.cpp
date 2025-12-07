#include <bits/stdc++.h>
using namespace std;
class A {
    int a;
public:
    void seta(int n){a = n;}
    void func(){cout<<"hello world\n";}
};
int main()
{
    A *p =NULL;
    p->func();
    return 0;
}
