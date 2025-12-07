#include <iostream>
 int main()
 {
 char password_enc[] = { 73,75, 65,71,80,66,95,65,28,22,70,                   
16,19,28,64,9,66,22,70,28,9,16,16,
66,29,9,70,21,20,20,9,23,22,20,
65,64,64,22,20,71,18,64,20,89
 };
 // 因为a^b=c时, b^c=a, 所以我们可以这样还原数据:
 char password[47];
 for (int i = 0; i < 45; i++) {
 password[i] = password_enc[i] ^ 36;
 }
 password[46] = 0; // 使用0字符来截断掉%s的无尽输出..
 printf("%s\n", password); // 哈哈，这就是本题的f l a g，自己运行一下交上去吧！
return 0;
 }