#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long sum5;
int main()
{
  int n;
  cin>>n;
  while(n!=0){
  	sum5+=(n/5);
  	n/=5;
  }
  cout<<sum5<<endl;
  return 0;
}