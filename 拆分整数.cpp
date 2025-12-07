#include <iostream>  
using namespace std;  
int main(int argc, char** argv)  
{  
    int n, m;  
    int count(int, int);  
    cin >> n >> m;  
    cout << count(n, m) << endl;  
    return 0;  
}  
int count( int n, int m ) 
{   
    if(n<1||m<1)return 0;
    else if(n==1||m==1)return 1;
        else if(n<m)return count(n,n);
            else if(n==m)return count(n,m-1)+1;
                 else return count(n-m,m)+count(n,m-1);
} 