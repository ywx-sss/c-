#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
 
using namespace std;
 //定义了19个由4×4的方块组成的俄罗斯方块
int block00[4][4] = { { 10,0,0,0 },{ 1,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 } };//"一"型 
int block01[4][4] = { { 11,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 } };//"I"型 
int block02[4][4] = { { 12,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 0,1,0,0 } };//"T"型 
int block03[4][4] = { { 13,0,0,0 },{ 0,1,0,0 },{ 1,1,0,0 },{ 0,1,0,0 } };//反"卜"型 
int block04[4][4] = { { 14,0,0,0 },{ 0,0,0,0 },{ 0,1,0,0 },{ 1,1,1,0 } };//倒"T"型 
int block05[4][4] = { { 15,0,0,0 },{ 0,1,0,0 },{ 0,1,1,0 },{ 0,1,0,0 } };//"卜"型 
int block06[4][4] = { { 16,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 1,0,0,0 } };//反 矮"7"型 
int block07[4][4] = { { 17,0,0,0 },{ 1,1,0,0 },{ 0,1,0,0 },{ 0,1,0,0 } };//"7"型 
int block08[4][4] = { { 18,0,0,0 },{ 0,0,0,0 },{ 0,0,1,0 },{ 1,1,1,0 } };//反 矮"L"型 
int block09[4][4] = { { 19,0,0,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 0,1,1,0 } };//"L"型 
int block10[4][4] = { { 20,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 0,0,1,0 } };//矮"7"型 
int block11[4][4] = { { 21,0,0,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 1,1,0,0 } };//反"L"型 
int block12[4][4] = { { 22,0,0,0 },{ 0,0,0,0 },{ 1,0,0,0 },{ 1,1,1,0 } };//矮"L"型 
int block13[4][4] = { { 23,0,0,0 },{ 0,1,1,0 },{ 0,1,0,0 },{ 0,1,0,0 } };//反"7"型 
int block14[4][4] = { { 24,0,0,0 },{ 0,0,0,0 },{ 0,1,1,0 },{ 1,1,0,0 } };//"S"型 
int block15[4][4] = { { 25,0,0,0 },{ 1,0,0,0 },{ 1,1,0,0 },{ 0,1,0,0 } };//竖"S"型 
int block16[4][4] = { { 26,0,0,0 },{ 0,0,0,0 },{ 1,1,0,0 },{ 0,1,1,0 } };//"Z"型 
int block17[4][4] = { { 27,0,0,0 },{ 0,0,1,0 },{ 0,1,1,0 },{ 0,1,0,0 } };//竖"Z"型 
int block18[4][4] = { { 28,0,0,0 },{ 0,0,0,0 },{ 1,1,0,0 },{ 1,1,0,0 } };//"O"型 
 
void initialWindow(HANDLE hOut);//初始化窗口
void initialPrint(HANDLE hOut);//初始化界面
void gotoXY(HANDLE hOut, int x, int y);//移动光标
void roundBlock(HANDLE hOut, int block[4][4]);//随机生成方块并打印到下一个方块位置
bool collisionDetection(int block[4][4], int map[21][12], int x, int y);//检测碰撞
void printBlock(HANDLE hOut, int block[4][4], int x, int y);//打印方块
void clearBlock(HANDLE hOut, int block[4][4], int x, int y);//消除方块
void myLeft(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y);//左移
void myRight(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y);//右移
void myUp(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y);//顺时针旋转90度
int myDown(HANDLE hOut, int block[4][4], int map[21][12], int &x, int y);//加速下落
void myStop(HANDLE hOut, int block[4][4]);//游戏暂停
void gameOver(HANDLE hOut, int block[4][4], int map[21][12]);//游戏结束
void eliminateRow(HANDLE hOut, int map[21][12], int &val, int &fraction, int &checkpoint);//判断是否能消行并更新分值
int main()
{
	int map[21][12];
	int blockA[4][4];//候选区的方块
	int blockB[4][4];//下落中的方块
	int positionX, positionY;//方块左上角的坐标
	bool check;//检查方块还能不能下落
	char key;//用来存储按键
	int val;//用来控制下落速度
	int fraction;//用来存储得分
	int checkpoint;//用来存储关卡
	int times;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获取标准输出设备句柄
	initialWindow(hOut);//初始化窗口 
initial:  //设置各变量初始值 
	gotoXY(hOut, 0, 0);
	initialPrint(hOut);
	check = true;
	val = 50;//初始速度为每下落一格需要50毫秒
	fraction = 0;
	checkpoint = 1;
	times = val;
	for (int i = 0; i < 20; ++i)//初始化方块地图
	{
		for (int j = 1; j < 11; ++j)
		{
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < 20; ++i)
	{
		map[i][0] = map[i][11] = 1;//画左右边框 
	}
	for (int i = 0; i < 12; ++i)
	{
		map[20][i] = 1;//画下边框 
	}
 
	srand((unsigned)time(NULL));//srand() 函数是伪随机数生成函数,需要一个整型数作为输入参数,产生的随机数序列取决于这个种子
	                           //如果相同的种子作为srand() 的输入参数，那么每次运行 rand() 时，将得到相同的随机数序列
	                          //为了保证每次使用 rand() 产生不同的随机数序列，将time() 函数作为种子 
	roundBlock(hOut, blockA);//随机生成候选区方块 
	while (true)//游戏开始循环 
	{
		if (check)//方块到达底部 扫描并消除填满的行，更新关卡及分数 
		{
			eliminateRow(hOut, map, val, fraction, checkpoint);//调用函数扫描并消除填满的行，更新关卡及分数  
			check = false;//check设为假 ，表示可以继续下落 
			positionX = -3;//初始化光标位置，表示将在此位置打印新的方块 
			positionY = 4;
			if (collisionDetection(blockA, map, positionX, positionY))	//若当前候选区的方块与方块地图碰撞（即有新方块下落到地图中）
			{
				for (int i = 0; i < 4; ++i)
				{
					for (int j = 0; j < 4; ++j)
					{
						blockB[i][j] = blockA[i][j];//将候选区方块变为即将下落的方块
					}
				}
				roundBlock(hOut, blockA);//重新生成候选区的方块
			}
			else// 若当前候选区的方块与方块地图不碰撞
			{
				gameOver(hOut, blockA, map);//调用游戏结束函数 
				goto initial;//回到initial处 
			}
		}
		printBlock(hOut, blockB, positionX, positionY);//打印下落方块 
		if (_kbhit())// 检测玩家键盘输入并调用相应函数 
		{
			key = _getch();// 保存玩家键盘输入数值 
			switch (key)
			{
			case 72: // 按上箭头键，方块顺时针旋转
				myUp(hOut, blockB, map, positionX, positionY);
				break;
			case 75:// 按左箭头键，方块向左移动一格
				myLeft(hOut, blockB, map, positionX, positionY);
				break;
			case 77: // 按右箭头键，方块向右移动一格
				myRight(hOut, blockB, map, positionX, positionY);
				break;
			case 80:// 按下箭头键，方块快速下落，到底部则固定 
				switch (myDown(hOut, blockB, map, positionX, positionY))
				{
				case 0: // 下落途中未碰撞到方块地图
					check = false;
					break;
				case 1: // 下落已经到达底部 ，check为真
					check = true;
					break;
				case 2://方块与地图顶端发生碰撞，游戏结束
					gameOver(hOut, blockB, map);
					goto initial;//回到initial处 
				default:
					break;
				}
				break;
			case 32:// 按下空格键，暂停游戏
				myStop(hOut, blockA);
				break;
			case 27:// 按下 Esc 键，退出游戏
				exit(0);
			default:
				break;
			}
		}
		Sleep(20);//<Windows.h> 头文件中的函数,用来控制方块下落的速度。具体来说，每个方块下落完后，调用 Sleep(20) 让程序休眠 20 毫秒，使得游戏速度适中
		if (0 == --times) //计时器times初始值为50，每过50毫秒更新一次方块位置 ， 
		{
			switch (myDown(hOut, blockB, map, positionX, positionY))
			{
			case 0:
				check = false;
				break;
			case 1:
				check = true;
				break;
			case 2:
				gameOver(hOut, blockB, map);
				goto initial;
			default:
				break;
			}
			times = val;//更新完毕计时器重新设置为50毫秒 
		}
	}
	cin.get();//从键盘读取字符 ，按任意键结束 
	return 0;
}
 
void initialWindow(HANDLE hOut)  //用来初始化控制台窗口 
{
	SetConsoleTitle("俄罗斯方块");//设置控制台窗口的标题为“俄罗斯方块”
	COORD size = { 80, 25 };//定义一个 COORD 结构体类型的变量 size，并初始化它的值为 (80,25)。表示控制台窗口缓冲区的大小是 80 行 25 列。
	SetConsoleScreenBufferSize(hOut, size);//设置控制台窗口的缓冲区大小为 size
	SMALL_RECT rc = { 0, 0, 79, 24 };//定义一个 SMALL_RECT 结构体类型的变量 rc，并初始化它的值为左上角为 (0,0)，右下角为 (79,24) 的矩形。 
	SetConsoleWindowInfo(hOut, true, &rc);//设置控制台窗口的大小为左上角为 (0,0)，右下角为 (79,24) 的矩形。
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };//定义一个 CONSOLE_CURSOR_INFO 结构体类型的变量 cursor_info，并初始化它的值为 (1,0)。这个结构体用来设置控制台光标的属性。
	SetConsoleCursorInfo(hOut, &cursor_info);//设置控制台光标的信息，在这里将光标设置为不可见。
}
 
void initialPrint(HANDLE hOut)  //用来初始化控制台窗口中的界面元素，包括游戏区域、分数、关卡、下一方块、操作方法、关于等等。 
{
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //设置输出文本的颜色属性为默认值，即白色。
	for (int i = 0; i < 20; ++i) //通过 for 循环输出游戏区域的 20 行，每行都包含两个方块和随机位置的星号，表示正在游戏的方块组合。
	{
		cout << "■                    ■☆                      ☆" << endl;
	}
	gotoXY(hOut, 24, 0); //将光标移动到指定位置，依次输出分数、关卡、下一方块、操作方法、关于等信息。
	cout << "☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆";
	gotoXY(hOut, 0, 20);
	cout << "■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆";
	gotoXY(hOut, 26, 1);
	cout << "分    数：      ";
	gotoXY(hOut, 26, 2);        //输出的 "分数"、"关卡" 等后面跟了一些空格，是为了留出相应的位置后面用来更新数据。
	cout << "关    卡：      "; //例如在后面调用 setScore() 函数时可以直接将新的分数值覆盖掉空格部分，实现分数的实时更新。
	gotoXY(hOut, 26, 4);
	cout << "下一方块：";
	gotoXY(hOut, 26, 9);
	cout << "操作方法：";
	gotoXY(hOut, 26, 11);
	cout << "↑：旋转 ↓：速降";
	gotoXY(hOut, 26, 12);
	cout << "→：右移 ←：左移";
	gotoXY(hOut, 26, 13);
	cout << "空格键：开始/暂停";
	gotoXY(hOut, 26, 14);
	cout << "Esc 键：退出";
	gotoXY(hOut, 26, 16);
	cout << "关    于：";
	gotoXY(hOut, 30, 18);
	cout << "俄罗斯方块";
	gotoXY(hOut, 30, 19);
	cout << "作者：某某某";
}
 
void gotoXY(HANDLE hOut, int x, int y)//作用是将控制台的光标移动到指定位置（x，y）
{
	COORD pos;//通过COORD结构体定义了一个pos变量，用来存储光标位置信息
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);//调用Windows API函数SetConsoleCursorPosition，将光标移动到指定位置。
}
 
void roundBlock(HANDLE hOut, int block[4][4]) //接收两个参数：一个控制台句柄hOut和一个44的整型数组block。该函数的作用是将block设置为19个预定义44方块之一，并在控制台上打印出来。
{
	clearBlock(hOut, block, 5, 15);//调用clearBlock函数清除控制台中block所占位置的输出，并设置其背景颜色为15。
	switch (rand() % 19)//使用随机数生成器得到一个0~18的整数，对应着19个预定义方块。
	{
	case 0:                                  //根据生成的随机数选取一个对应的预定义方块，将block赋值为这个方块。
                                            //每个case内部都是一个双重循环，将对应预定义方块的值复制到block中。 
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block00[i][j];
			}
		}
		break;
	case 1:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block01[i][j];
			}
		}
		break;
	case 2:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block02[i][j];
			}
		}
		break;
	case 3:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block03[i][j];
			}
		}
		break;
	case 4:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block04[i][j];
			}
		}
		break;
	case 5:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block05[i][j];
			}
		}
		break;
	case 6:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block06[i][j];
			}
		}
		break;
	case 7:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block07[i][j];
			}
		}
		break;
	case 8:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block08[i][j];
			}
		}
		break;
	case 9:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block09[i][j];
			}
		}
		break;
	case 10:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block10[i][j];
			}
		}
		break;
	case 11:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block11[i][j];
			}
		}
		break;
	case 12:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block12[i][j];
			}
		}
		break;
	case 13:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block13[i][j];
			}
		}
		break;
	case 14:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block14[i][j];
			}
		}
		break;
	case 15:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block15[i][j];
			}
		}
		break;
	case 16:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block16[i][j];
			}
		}
		break;
	case 17:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block17[i][j];
			}
		}
		break;
	case 18:
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				block[i][j] = block18[i][j];
			}
		}
		break;
	default:
		break;
	}
	printBlock(hOut, block, 5, 15);//调用printBlock函数在控制台上打印出当前的block。
}
 
bool collisionDetection(int block[4][4], int map[21][12], int x, int y)//碰撞检测功能，可以用来检测当前下落的方块是否与已放置的方块重叠或者超出游戏区域边界。
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (x + i >= 0 && y + j >= 0 && map[x + i][y + j] == 1 && block[i][j] == 1)// x + i >= 0 && y + j >= 0 的意思是，只有当方块矩阵中每个元素所属的游戏区域位置坐标都不小于0时，
                                                                                      //碰撞检测才会继续进行。这是因为游戏区域的左上角坐标是(0,0)，当方块移动到左边界或者上边界以外时，
			{                                                                    //就不需要再进行碰撞检测了，因为这些位置已经超出了游戏区域的范围。例如，当方块在游戏区域的最上面一行时，
				return false;  //碰撞，0                                                //如果没有 x + i >= 0 && y + j >= 0 的判断条件，那么函数就会检测到方块与游戏区域上方的位置发生了碰撞，
			}                                                                  //从而导致游戏无法正常进行。而通过添加这个判断条件，可以避免这种情况的发生，保证游戏的顺利进行。 
		}
	}
	return true;//未碰撞，1 
}
 
void printBlock(HANDLE hOut, int block[4][4], int x, int y)//打印方块 
{
	switch (block[0][0])//switch语句，用于根据方块类型设置输出颜色。其中block[0][0]表示方块矩阵中的第一个方块，不同类型的方块在此位置上有不同的数值。
	{
	case 10:
	case 11:
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		break;
	case 12:
	case 13:
	case 14:
	case 15:
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		break;
	case 16:
	case 17:
	case 18:
	case 19:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		break;
	case 20:
	case 21:
	case 22:
	case 23:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		break;
	case 24:
	case 25:
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		break;
	case 26:
	case 27:
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		break;
	case 28:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		break;
	default:
		break;
	}
	for (int i = 0; i < 4; ++i)// 绘制方块矩阵
	{
		if (i + x >= 0)// 判断是否越界下落区域
		{
			for (int j = 0; j < 4; ++j)
			{
				if (block[i][j] == 1)// 如果该位置存在方块，则绘制该方块
				{
 
					gotoXY(hOut, 2 * (y + j), x + i);// 将光标移动到相应位置
					cout << "■";                    //由于绘制俄罗斯方块时，每个方块需要占用两个字符的位置，因此需要将y坐标乘以2
				}
			}
		}
	}
}
 
void clearBlock(HANDLE hOut, int block[4][4], int x, int y)//用于清除俄罗斯方块,将一个4*4的方块矩阵从指定坐标位置（x, y）中移除，并将该位置恢复为空白。
{
	for (int i = 0; i < 4; ++i)//遍历方块矩阵
	{
		if (i + x >= 0) // 判断是否超出游戏区域上边缘
		{
			for (int j = 0; j < 4; ++j)
			{
				if (block[i][j] == 1)// 如果该位置存在方块，则清空该位置
				{
					gotoXY(hOut, 2 * (y + j), x + i);// 将光标移动到相应位置
					cout << "  ";// 清空该位置
				}
			}
		}
	}
}
 
void gameOver(HANDLE hOut, int block[4][4], int map[21][12])//在游戏结束时弹出提示窗口的函数
{
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);//将控制台文字颜色设置为亮红色，以突出弹出窗口中的“GAME OVER”字样。
	gotoXY(hOut, 9, 8);// 将光标移动到指定位置
	cout << "GAME OVER";
	gotoXY(hOut, 8, 9);
	cout << "空格键：重来";
	gotoXY(hOut, 8, 10);
	cout << "ESC键：退出";
	char key;//定义一个char类型的变量key，用于存储用户按下的键盘按键的值。
	while (true)
	{
		key = _getch();
		if (key == 32)//如果用户按下了空格键，则直接返回
		{
			return;
		}
		if (key == 27)//如果用户按下了ESC键，则通过exit函数退出程序。
		{
			exit(0);
		}
	}
}
 
int myDown(HANDLE hOut, int block[4][4], int map[21][12], int &x, int y)// 如果方块下降一格会与地图或者其他方块发生碰撞，就将方块放置在地图上
{
	if (collisionDetection(block, map, x + 1, y))//碰撞检测，若未碰撞，则继续下降 
	{
		clearBlock(hOut, block, x, y);//清除当前方块 
		++x;//横坐标下降一格 
		return 0;//返回0，表示方块可以继续下降 
	}
	if (x < 0)// 与地图碰撞，返回2，表示方块已经到达游戏区域的上限
	{
		return 2;
	}
	for (int i = 0; i < 4; ++i)//未与地图或方块碰撞，则将方块放置在地图上 
	{
		for (int j = 0; j < 4; ++j)
		{
			if (block[i][j] == 1)// 如果方块矩阵中该位置上有方块 
			{
				map[x + i][y + j] = 1;// 在地图上标记该位置被占用 
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);// // 设置文字颜色为亮白色 
				gotoXY(hOut, 2 * (y + j), x + i);//光标移动到指定位置上输出方块 
				cout << "■";
			}
		}
	}
	return 1;// 返回1，表示方块成功固定在地图上
}
 
void myLeft(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y)// 操作方块向右移动的函数，与myDown思路相似 
{
	if (collisionDetection(block, map, x, y - 1))
	{
		clearBlock(hOut, block, x, y);
		--y;
	}
}
 
void myRight(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y)//操作方块向右移动的函数，与myLeft思路相似 
{
	if (collisionDetection(block, map, x, y + 1))
	{
		clearBlock(hOut, block, x, y);
		++y;
	}
}
 
void myUp(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y)//旋转方块 
{
	switch (block[0][0])//switch-case语句用于判断当前方块形状
	{                   //当前生成的block[0][0]中储存着代表其类型的值10~28，依据数值进行不同类型的旋转操作 
	case 10://以case10为例，block[0][0]中储存值为10代表"一"型方块 
		if (collisionDetection(block01, map, x, y))//碰撞检测，若返回值为真，则旋转后未碰撞，可以旋转 
		{
			clearBlock(hOut, block, x, y);//利用函数清除当前方块 
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block01[i][j];//打印block01类型方块，即"一"旋转后对应的"I"型方块 
				}
			}
		}
		break;
	case 11:
		if (collisionDetection(block00, map, x, y))//旋转后未碰撞，则旋转 
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block00[i][j];
				}
			}
		}
		else if (collisionDetection(block00, map, x, y - 1))//如果旋转后发生碰撞，尝试向上、下、左、右移动一格并重新检测是否会发生碰撞。
		{                                                  //若能移动一格避免碰撞，就将方块移动一格。若不能，则继续向上、下、左、右移动两格直到找到合适的位置。 
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block00[i][j];
				}
			}
			--y;
		}
		else if (collisionDetection(block00, map, x, y + 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block00[i][j];
				}
			}
			++y;
		}
		else if (collisionDetection(block00, map, x, y - 2))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block00[i][j];
				}
			}
			y = y - 2;
		}
		else if (collisionDetection(block00, map, x, y + 2))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block00[i][j];
				}
			}
			y = y + 2;
		}
		break;
	case 12:
		if (collisionDetection(block03, map, x, y))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block03[i][j];
				}
			}
		}
		else if (collisionDetection(block03, map, x, y - 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block03[i][j];
				}
			}
			--y;
		}
		else if (collisionDetection(block03, map, x, y + 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block03[i][j];
				}
			}
			++y;
		}
		break;
	case 13:
		if (collisionDetection(block04, map, x, y))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block04[i][j];
				}
			}
		}
		else if (collisionDetection(block04, map, x, y - 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block04[i][j];
				}
			}
			--y;
		}
		else if (collisionDetection(block04, map, x, y + 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block04[i][j];
				}
			}
			++y;
		}
		break;
	case 14:
		if (collisionDetection(block05, map, x, y))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block05[i][j];
				}
			}
		}
		else if (collisionDetection(block05, map, x, y - 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block05[i][j];
				}
			}
			--y;
		}
		else if (collisionDetection(block05, map, x, y + 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block05[i][j];
				}
			}
			++y;
		}
		break;
	case 15:
		if (collisionDetection(block02, map, x, y))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block02[i][j];
				}
			}
		}
		else if (collisionDetection(block02, map, x, y - 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block02[i][j];
				}
			}
			--y;
		}
		else if (collisionDetection(block02, map, x, y + 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block02[i][j];
				}
			}
			++y;
		}
		break;
 
	case 16:
		if (collisionDetection(block07, map, x, y))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block07[i][j];
				}
			}
		}
		else if (collisionDetection(block07, map, x, y - 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block07[i][j];
				}
			}
			--y;
		}
		else if (collisionDetection(block07, map, x, y + 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block07[i][j];
				}
			}
			++y;
		}
		break;
	case 17:
		if (collisionDetection(block08, map, x, y))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block08[i][j];
				}
			}
		}
		else if (collisionDetection(block08, map, x, y - 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block08[i][j];
				}
			}
			--y;
		}
		else if (collisionDetection(block08, map, x, y + 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block08[i][j];
				}
			}
			++y;
		}
		break;
	case 18:
		if (collisionDetection(block09, map, x, y))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block09[i][j];
				}
			}
		}
		else if (collisionDetection(block09, map, x, y - 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block09[i][j];
				}
			}
			--y;
		}
		else if (collisionDetection(block09, map, x, y + 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block09[i][j];
				}
			}
			++y;
		}
		break;
	case 19:
		if (collisionDetection(block06, map, x, y))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block06[i][j];
				}
			}
		}
		else if (collisionDetection(block06, map, x, y - 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block06[i][j];
				}
			}
			--y;
		}
		else if (collisionDetection(block06, map, x, y + 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block06[i][j];
				}
			}
			++y;
		}
		break;
	case 20:
		if (collisionDetection(block11, map, x, y))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block11[i][j];
				}
			}
		}
		else if (collisionDetection(block11, map, x, y - 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block11[i][j];
				}
			}
			--y;
		}
		else if (collisionDetection(block11, map, x, y + 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block11[i][j];
				}
			}
			++y;
		}
		break;
	case 21:
		if (collisionDetection(block12, map, x, y))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block12[i][j];
				}
			}
		}
		else if (collisionDetection(block12, map, x, y - 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block12[i][j];
				}
			}
			--y;
		}
		else if (collisionDetection(block12, map, x, y + 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block12[i][j];
				}
			}
			++y;
		}
		break;
	case 22:
		if (collisionDetection(block13, map, x, y))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block13[i][j];
				}
			}
		}
		else if (collisionDetection(block13, map, x, y - 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block13[i][j];
				}
			}
			--y;
		}
		else if (collisionDetection(block13, map, x, y + 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block13[i][j];
				}
			}
			++y;
		}
		break;
	case 23:
		if (collisionDetection(block10, map, x, y))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block10[i][j];
				}
			}
		}
		else if (collisionDetection(block10, map, x, y - 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block10[i][j];
				}
			}
			--y;
		}
		else if (collisionDetection(block10, map, x, y + 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block10[i][j];
				}
			}
			++y;
		}
		break;
	case 24:
		if (collisionDetection(block15, map, x, y))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block15[i][j];
				}
			}
		}
		else if (collisionDetection(block15, map, x, y - 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block15[i][j];
				}
			}
			--y;
		}
		else if (collisionDetection(block15, map, x, y + 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block15[i][j];
				}
			}
			++y;
		}
		break;
	case 25:
		if (collisionDetection(block14, map, x, y))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block14[i][j];
				}
			}
		}
		else if (collisionDetection(block14, map, x, y - 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block14[i][j];
				}
			}
			--y;
		}
		else if (collisionDetection(block14, map, x, y + 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block14[i][j];
				}
			}
			++y;
		}
		break;
	case 26:
		if (collisionDetection(block17, map, x, y))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block17[i][j];
				}
			}
		}
		else if (collisionDetection(block17, map, x, y - 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block17[i][j];
				}
			}
			--y;
		}
		else if (collisionDetection(block17, map, x, y + 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block17[i][j];
				}
			}
			++y;
		}
		break;
	case 27:
		if (collisionDetection(block16, map, x, y))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block16[i][j];
				}
			}
		}
		else if (collisionDetection(block16, map, x, y - 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block16[i][j];
				}
			}
			--y;
		}
		else if (collisionDetection(block16, map, x, y + 1))
		{
			clearBlock(hOut, block, x, y);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					block[i][j] = block16[i][j];
				}
			}
			++y;
		}
		break;
	default:
		break;
	}
}
 
void myStop(HANDLE hOut, int block[4][4])//实现了游戏的暂停功能，并且在暂停期间显示提示信息，直到用户按下空格键或 Esc 键
{
	clearBlock(hOut, block, 5, 15);//清除当前方块
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	gotoXY(hOut, 30, 7);//定位控制台光标位置
	cout << "游戏暂停";
	char key;
	while (true)
	{
		key = _getch();//获取用户按下的键
		if (key == 32)//如果用户按下空格键，则继续游戏
		{
			gotoXY(hOut, 30, 7);//光标定位到文字处 
			cout << "        ";//清空提示文字
			printBlock(hOut, block, 5, 15);//重新打印当前方块
			return;//返回游戏 
		}
		if (key == 27)//如果用户按下 Esc 键，则调用exit函数退出游戏 
		{
			exit(0);
		}
	}
}
 
void eliminateRow(HANDLE hOut, int map[21][12], int &val, int &fraction, int &checkpoint)//判断并消除已经填满的行，同时更新分数和关卡。剩余行下坠到空缺的位置。 
{
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);//设置控制台的前景色为白色
	for (int i = 19; i >= 0; --i)//从最后一行开始扫描
	{
		int x = 0;
		for (int j = 1; j < 11; ++j)//计算该行已填充的方块数
		{
			x += map[i][j];
		}
		if (x == 10)//如果该行已经被填满
		{
			fraction += 100;//则分值增加100分
			if (val > 1 && fraction / 1000 + 1 != checkpoint)
			{
				checkpoint = fraction / 1000 + 1;//分值每满1000关卡数+1 
				val -= 5;
			}
			for (int m = i; m > 0; --m)//从被扫描行开始，将上面的所有行下移一行
			{
				for (int n = 1; n < 11; ++n)//把上一行数组值赋给下一行数组 
				{
					map[m][n] = map[m - 1][n]; 
					gotoXY(hOut, 2 * n, m);
					if (map[m][n] == 1)//打印该行 
					{
						cout << "■";
					}
					else
					{
						cout << "  ";
					}
				}
			}
			++i;//往下一行继续扫描 
		}
	}
	gotoXY(hOut, 36, 1);//定位光标，输出分值 
	cout << fraction;
	gotoXY(hOut, 36, 2);//定位光标，输出关卡数 
	cout << checkpoint;
}