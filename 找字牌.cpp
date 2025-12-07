#include <iostream> 
#include <bits/stdc++.h> 
using namespace std; 
int main() 
{ 
  int x,a,b,num,sum,flag=0,s1,s2; 
  cin>>x>>a>>b; 
  for(int i=a;i<=b;i++){ 
     sum=i;flag=0; 
      for(int j=9;j>=1;j--){ 
          if(int(sum/pow(10,j-1))!=0){ 
             num=sum/(pow(10,j-1)); 
              if(num>x){ 
                flag=1; 
                break; 
              } 
        sum%=int((pow(10,j-1))); 
       } 
      else continue; 
      } 
   if(flag==0){
      s1=; 
      break;
   }
  } 
  for(int i=b;i>=a;i--){ 
     sum=i;flag=0; 
      for(int j=9;j>=1;j--){ 
          if(int(sum/pow(10,j-1))!=0){ 
             num=sum/(pow(10,j-1)); 
              if(num>x){ 
                flag=1; 
                break; 
              } 
        sum%=int((pow(10,j-1))); 
       } 
      else continue; 
      } 
   if(flag==0){
   s2=; 
   break;
   }
  } 
  cout<<ans<<endl; 
  return 0; 
}  