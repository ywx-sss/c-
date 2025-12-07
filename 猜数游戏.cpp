#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace  std;
int main()
{
	srand((unsigned)time(0));
	int a = rand() % 100 + 1;
	int c;
	while (true)
	{
		cout << "输入1~100的随机数："; 
		cin >> c;
		if (c > a) cout << "猜大了" << endl;
		else if(c<a)cout << "猜小了" << endl;
		else
		{
			cout << "猜对了" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}