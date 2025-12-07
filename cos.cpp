#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double  cosx=1,cosxi=1;
double jiecheng(int i){
	double sum=1;
	for(int j=i;j>=1;j--){
		sum*=j;
	}
	return sum;
}
double powe(double xpi,int i){
	double sum=1;
	for(int j=1;j<=i;j++){
		sum*=xpi;
	}
	return sum;
}
int main()
{
  double x,xpi;
  int i;
  cin>>x;
  xpi=x*3.1415926535897923/180;
  for(i=1;cosxi>0.000001;i++){
  	cosxi=powe(xpi,2*i)/jiecheng(2*i);
  	if(i%2==1)cosx-=cosxi;
  	else cosx+=cosxi;
  }
  cout<<"i="<<i-1<<", "<<"cos("<<x<<")="<<fixed<<setprecision(6)<<"cos("<<xpi<<")="<<cosx<<endl;
  return 0;
}