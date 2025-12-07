#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>  
#include<stdlib.h>  
void dongtai(int m,int n){
	char **a;
	a=(char**)malloc(sizeof(char*)*m);  
    for(int i=0;i<m;i++)  
    a[i]=(char*)malloc(sizeof(char)*n);  
    for(int i=0;i<m;i++)  
    {
        for(int j=0;j<n;j++)  
        {
        	a[i][j]=' ';
            printf("%c1",a[i][j]);     //输出每个元素地址，每行的列与列之间的地址时连续的，行与行之间的地址不连续
        }
        printf("\n");
    }
}
int main()  
{    
    int m,n;  
    scanf("%d",&m);  
    scanf("%d",&n);  //m行数，n列数
    dongtai(m,n);
    return 0;  
}