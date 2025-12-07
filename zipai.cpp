#include <iostream>  
#include <bits/stdc++.h>  
using namespace std;  
int main()  
{  
  int x,s1[11]={0},s2[11]={0},num,w1,w2;  
  string a,b;  
  cin>>x>>a>>b;  
  for(int i=10;i>10-a.size();i--){  
      s1[i]=a[i+a.size()-11];s1[i]-=48;  
  }  
  for(int i=10;i>10-b.size();i--){  
    s2[i]=b[i+b.size()-11];s2[i]-=48;  
  }  
  num=b.size();  
  s1[10]--;  
  int flag=1; 
  while(flag){     
  s1[10]++;flag=0;w1=0;  
    for(int i=10;i>=10-num;i--){  
        if(s1[i]>9){  
            s1[i]-=10;  
            s1[i-1]+=1;  
        }  
    } 
    for(int i=10;i>=1;i--){  
       if(s1[i]>x){ 
         flag=1; 
       } 
      else w1+=s1[i]*pow(x+1,10-i);  
    }  
  }  
  flag=1;s2[10]++; 
  while(flag){     
  s2[10]--;flag=0;w2=0;  
    for(int i=10;i>=10-num;i--){  
        if(s2[i]<0){  
            s2[i]+=10;  
            s2[i-1]-=1;  
    } 
    for(int i=10;i>=1;i--){  
       if(s2[i]>x){ 
        flag=1; 
       } 
      else w2+=s2[i]*pow(x+1,10-i); 
    }  
  }  
  }
  cout<<w2-w1+1<<endl; 
  return 0;  
}  