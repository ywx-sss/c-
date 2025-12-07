#include <iostream>
using namespace std;
int a[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31 };
int day(int y,int m,int d) 
{
    
    if (y%4==0&&y%100!=0||y%400==0) a[2]=29;
    else a[2]=28;
    int s;
    for(int i=1;i<=m-1;i++) {
	d+=a[i];
	}
    s=365*(y-1)+(y-1)/4-(y-1)/100+(y-1)/400+d;
    return s;
}
main() 
{
    int y1,y2,m1,m2,d1,d2;
    cin>>y1>>m1>>d1>>y2>>m2>>d2;
    if(day(y2,m2,d2)-day(y1,m1,d1)!=1)
    cout<<day(y2,m2,d2)-day(y1,m1,d1)<<" days"<<endl;
    else cout<<day(y2,m2,d2)-day(y1,m1,d1)<<" day"<<endl;
}
