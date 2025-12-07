#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long sum2,sum5;
int main()
{
  int a,b,num=1;char s;
  cin>>a>>s>>b;
  cout<<a/b;
  if(a%b!=0)cout<<".";
  while(a%b!=0&&num<=200){
    a%=b;
  	a=(a%b)*10;
  	cout<<a/b;
  	num++;
  }
  cout<<endl;
  return 0;
}