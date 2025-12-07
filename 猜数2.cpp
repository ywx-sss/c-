#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace  std;
int main()
{
	srand((unsigned)time(0));
	int a = rand() % 1000 + 1,num=10;
	int c;
	while (true)
	{   num--;
		cout << "输入1~1000的随机数："; 
		cin >> c;
		if (c > a) cout << "猜大了,你还有" <<num<<"次机会"<< endl;
		else if(c<a)cout << "猜小了,你还有" <<num<<"次机会"<< endl;
		else
		{
			cout << "猜对了,牛逼" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}