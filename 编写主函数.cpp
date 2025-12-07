#include <bits/stdc++.h>
using namespace std;
int leap_year( int );     
int year_days( int );     
int days(int, int, int);      
int leap_year( int year )   // 判断闰年或平年  
{   return ( (year%4==0 && year%100!=0) || year%400==0 ) ? 1 : 0;  
}  
  
int year_days(int year)     // 计算一整年的天数  
{   return leap_year( year ) ? 366 : 365;  
}  
  
int days( int year, int month, int day ) // 计算该天month,day 是本年year的第几天  
{   int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}, i;  
      
    if  ( leap_year( year ) && month >2 )  
        day++;  
      
    for ( i=1; i<month; i++ )  
        day += months[i];  
  
    return day;  
}  
int main(){
	int y1,y2,m1,m2,d1,d2,num=0;
	cin>>y1>>m1>>d1>>y2>>m2>>d2;
	for(int i=y1;i<y2;i++){
		num+=year_days(i);
	}
	num+=(days(y2,m2,d2)-days(y1,m1,d1));
	if(num==1)cout<<num<<" Day";
	else cout<<num<<" Days";
	return 0;
}