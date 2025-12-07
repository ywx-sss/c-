#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool shubi(int a[],int b[],int l1,int l2){
	if(l1>l2)return 1;
	if(l1<l2)return 0;
	if(l1==l2){
		for(int i=1;i<=500;i++){
			if(a[i]>b[i])return 1;
			if(a[i]<b[i])return 0;
		}
		return 1;
	}
}
int main()
{
  int n;
  cin>>n;
  for(int m=1;m<=n;m++){
  int len1,len2,fu,jin=0,flag=0;string s;
  int sum1[502]={0},sum2[502]={0};
  cin>>s;
  for(int i=0;i<=s.size()-1;i++){
  	if(s[i]=='+'||s[i]=='-'){
  		fu=i;len1=i;break;
	  }
	  else{
	  	sum1[i+1]=s[i]-48;
	  }
  }
  for(int i=fu+1;i<=s.size()-1;i++){
	  	sum2[i-fu]=s[i]-48;
  }len2=s.size()-1-fu;
  if(s[fu]=='+'){
  	if(len1>=len2){
  		for(int i=0;i<=len2||jin==1;i++){
  			if(len2-i>=0){
  			if(sum1[len1-i]+sum2[len2-i]+jin<10){
			  sum1[len1-i]+=(sum2[len2-i]+jin);
			  jin=0;
			}
			else{
			  sum1[len1-i]+=(sum2[len2-i]+jin-10);
			  jin=1;
			}}
			else{
			 if(sum1[len1-i]+jin<10){
			  sum1[len1-i]+=jin;
			  jin=0;
			}
			else{
			  sum1[len1-i]+=(jin-10);
			  jin=1;
			}
		}}	
		for(int i=0;i<=len1;i++)if(sum1[i]!=0||flag==1){
		cout<<sum1[i];flag=1;}
	}
	else{
  		for(int i=0;i<=len1||jin==1;i++){
  			if(len1-i>=0){
  			if(sum2[len2-i]+sum1[len1-i]+jin<10){
			  sum2[len2-i]+=(sum1[len1-i]+jin);
			  jin=0;
			}
			else{
			  sum2[len2-i]+=(sum1[len1-i]+jin-10);
			  jin=1;
			}}
			else{
			 if(sum2[len2-i]+jin<10){
			  sum2[len2-i]+=jin;
			  jin=0;
			}
			else{
			  sum2[len2-i]+=(jin-10);
			  jin=1;
			}
		}}	
		for(int i=0;i<=len2;i++)if(sum2[i]!=0||flag==1){
		cout<<sum2[i];flag=1;}
	}
  }
  if(s[fu]=='-'){
  	if(shubi(sum1,sum2,len1,len2)){
    	for(int i=0;i<=len2||jin==1;i++){
    		if(len2-i>=0){
  			if(sum1[len1-i]-sum2[len2-i]-jin<0){
			  sum1[len1-i]-=(sum2[len2-i]+jin-10);
			  jin=1;
			}
			else{
			  sum1[len1-i]-=(sum2[len2-i]+jin);
			  jin=0;
			}
			}
			else{
				if(sum1[len1-i]-jin<0){
			  sum1[len1-i]-=(jin-10);
			  jin=1;
			}
			else{
			  sum1[len1-i]-=(jin);
			  jin=0;
			}
			}
		}
        for(int i=1;i<=len1;i++)
		if(sum1[i]!=0||flag==1){
		cout<<sum1[i];flag=1;
		}}
	else{	
	    
		for(int i=0;i<=len1||jin==1;i++){
    		if(len1-i>=0){
  			if(sum2[len2-i]-sum1[len1-i]-jin<0){
			  sum2[len2-i]-=(sum1[len1-i]+jin-10);
			  jin=1;
			}
			else{
			  sum2[len2-i]-=(sum1[len1-i]+jin);
			  jin=0;
			}
			}
			else{
				if(sum2[len2-i]-jin<0){
			  sum2[len2-i]-=(jin-10);
			  jin=1;
			}
			else{
			  sum2[len2-i]-=(jin);
			  jin=0;
			}
			}
		}
		cout<<"-";
        for(int i=1;i<=len2;i++)
		if(sum2[i]!=0||flag==1){
		cout<<sum2[i];flag=1;
		}
    }
  }
  if(flag==0)cout<<"0";
  cout<<endl;
  }
  return 0;
}