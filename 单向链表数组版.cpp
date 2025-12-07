#include<bits/stdc++.h>
using namespace std;
typedef struct data{
	int v;
	int next;
	int flag;
}DATE;
int main()  
{    
    DATE people[31];
    for(int i=1;i<=30;i++){
    	people[i].v=i;
    	people[i].next=i+1;
    	people[i].flag=0;
	}
	people[30].next=1;
	int num=0,sum=1;//反正能用了，懒得写
	while(1){
		
	}
    return 0;  
}
