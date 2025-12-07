#include <iostream>  
#include <math.h>  
using namespace std;
int isPrime(int n)
{
	if(n <= 1){
		return 0;
	}
    for (int i = 2; i <=sqrt(n); i++)
    {
        if ((n % i) == 0){
            return 0;
        }
    }
    return 1;
}
int main()  
{  
    int n, m;  
    int isPrime( int );  // 若是素数函数isPrim返回1，否则返回0   
    cin >> n >> m;  
    while ( n < m-1 )  
    {  
        if ( isPrime(n) && isPrime(n+2) )  
        {  
            cout << n << "," << n+2 << endl;  
        }  
        n++;  
    }  
    return 0;  
}  