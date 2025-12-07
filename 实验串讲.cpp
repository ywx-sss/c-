#include <math.h>     //定义数学函数
#include <stdio.h>     //定义输入／输出函数
#include <stdlib.h>    //定义杂项函数及内存分配函数
#include <string.h>    //字符串处理
//头文件，包含了函数库，以上是常用以及有用的头文件
#define A 10
#define B A+10
//宏定义（后文中出现的所有A就是10，所有的B就是A+10）
int main()//主函数（执行的部分）
{     int a,b,sum1,sum2;
      int add(int,int);
      scanf("%d%d",&a,&b);//输入
      sum1=add(a,b);
      sum2=add(A,B);
      printf("sum1= %d sum2= %d\n",sum1,sum2);//输出
      return 0;
}
int add(int x,int y)//函数
{   int z;
    z=x+y;
    return z;
}