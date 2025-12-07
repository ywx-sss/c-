#include<cstdio>
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<windows.h>
#include <conio.h>
using namespace std;
#define frame_width 50
#define frame_height 25

typedef struct{
    int x,y;
} Food;
typedef struct{
    int x[100],y[100],len,state;
} Snake;

void gotoxy(int x,int y);  //最重要的一个函数，控制光标的位置
void print_map();
void get_newfood();//生成新食物
bool check_foodinsnake();//检查新食物有没有在蛇身上
void move_snake();
void check_foodeating();
bool check_snakealive();


//需要用到的全局变量
int score;
Snake snake;
Food food;
bool check_eaten;

int main()
{
    system("color 0B");
    do
    {
        system("cls");
        print_map();
        score=0,check_eaten=0;
        //贪吃蛇的每回合运行控制
        while(1)
        {
            check_foodeating();//system("pause");
            move_snake();
            Sleep(max(50,300-score));//控制速度（与长度呈反比）
            if(!check_snakealive())
                break;
        }
        printf("Game Over!\n");
        printf("1:Restart\t2:exit\n");
        char com2;
        cin>>com2;
        if(com2=='2')
            break;
    }while(1);
}

void gotoxy(int x,int y)
{
    COORD pos;//COORD是一种自带结构体，表示一个字符在控制台屏幕上的坐标
    HANDLE han=GetStdHandle(STD_OUTPUT_HANDLE); //从标准输出设备里取出一个句柄
    pos.X=y,pos.Y=x;
    SetConsoleCursorPosition(han,pos);//定位光标的函数
}

void print_map()
{
    //打印墙壁
    for(int i=0;i<frame_height;i++)
    {
        gotoxy(i,0);
        printf("#");
        gotoxy(i,frame_width-1);//因为这个标记是长度，从零开始所以最后要减1
        printf("#");
    }
    for(int i=0;i<frame_width;i++)
    {
        gotoxy(0,i);
        printf("#");
        gotoxy(frame_height-1,i);
        printf("#");
    }

    //蛇身初始化
    snake.len=3;
    snake.state='w';
    snake.x[1]=frame_height/2;
    snake.y[1]=frame_width/2;
    gotoxy(snake.x[1],snake.y[1]);
    printf("@");
    for(int i=2;i<=snake.len;i++)
    {
        snake.x[i]=snake.x[i-1]+1;
        snake.y[i]=snake.y[i-1];
        gotoxy(snake.x[i],snake.y[i]);
        printf("@");
    }

    //打印初始食物
    get_newfood();

    //打印右边状态栏
    gotoxy(2,frame_width+3);
    printf("WELCOME TO THE GAME OF RETRO SNAKE");
    gotoxy(4,frame_width+3);
    printf("UP:   w");
    gotoxy(6,frame_width+3);
    printf("DOWN: s");
    gotoxy(8,frame_width+3);
    printf("LEFT: a");
    gotoxy(10,frame_width+3);
    printf("RIGHT:d");
    gotoxy(12,frame_width+3);
    printf("Your score:%d",score);
}

bool check_foodinsnake()
{
    for(int i=1;i<=snake.len;i++)
        if(snake.x[i]==food.x&&snake.y[i]==food.y)
            return 1;
    return 0;
}

void get_newfood()
{
    do{
        srand(time(0));
        food.x=rand()%(frame_height-2)+1;
        food.y=rand()%(frame_width-2)+1;
    }while(check_foodinsnake());
    gotoxy(food.x,food.y);
    cout<<"$";
}

void move_snake()
{
    char com;
    while(kbhit())//键盘有输入
        com=getch();//从控制台读取一个字符，但不显示在屏幕上
    //没有吃到去除蛇尾
    if(!check_eaten)
    {
        gotoxy(snake.x[snake.len],snake.y[snake.len]);
        printf(" ");
    }
    //将除蛇头外的其他部分向前移动
    for(int i=snake.len;i>1;i--)
        snake.x[i]=snake.x[i-1],
        snake.y[i]=snake.y[i-1];
    //移动蛇头
    switch(com)
    {
        case 'w':
        {
            if(snake.state=='s') //如果命令与当前方向相反不起作用
                snake.x[1]++;
            else
                snake.x[1]--,snake.state='w';
            break;
        }
        case 's':
        {
            if(snake.state=='w')
                snake.x[1]--;
            else
                snake.x[1]++,snake.state='s';
            break;
        }
        case 'a':
        {
            if(snake.state=='d')
                snake.y[1]++;
            else
                snake.y[1]--,snake.state='a';
            break;
        }
        case 'd':
        {
            if(snake.state=='a')
                snake.y[1]--;
            else
                snake.y[1]++,snake.state='d';
            break;
        }
        default: //按其余键保持状态前进
        {
            if(snake.state=='s')
                snake.x[1]++;
            else if(snake.state=='w')
                snake.x[1]--;
            else if(snake.state=='d')
                snake.y[1]++;
            else if(snake.state=='a')
                snake.y[1]--;
            break;
        }
    }
    gotoxy(snake.x[1],snake.y[1]);
    printf("@");
    check_eaten=0;
    gotoxy(frame_height,0);
}

void check_foodeating()
{
    if(snake.x[1]==food.x&&snake.y[1]==food.y)
    {
        score+=10;
        check_eaten=1;
        gotoxy(12,frame_width+3);
        printf("Your score:%d",score);
        snake.len++;
        get_newfood();
    }
}

bool check_snakealive()
{
    //检查有没有撞到墙
    if(snake.x[1]==0||snake.x[1]==frame_height-1||snake.y[1]==0||snake.y[1]==frame_width-1)//撞墙
           return 0;
    //检查有没有吃到自己
    for(int i=2;i<=snake.len;i++)
        if(snake.x[i]==snake.x[1]&&snake.y[i]==snake.y[1])
            return 0;
    return 1;
}

