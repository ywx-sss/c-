#include <bits/stdc++.h>
using namespace std;
int main(){
	int year,mouth,day;
	cin>>year>>mouth>>day;
	if(mouth==1){
		year--;mouth=13;
	}
	if(mouth==2){
		year--;mouth=14;
	}
	cout<<(day+2*mouth+3*(mouth+1)/5/*从三月开始符合的公式*/+year+year/4-year/100+year/400+1)%7<<endl;
	/*对全月分使用的公式可以复习https://www.cnblogs.com/faterazer/p/11393521.html*/
	return 0;
}