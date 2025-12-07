#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,tem,temlast=50,l=1,day=0,ansday=0,flag=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>tem;	
    	if(temlast>=tem){
    		day++;
		}	
		else{
			if(day>ansday){
				ansday=day;
				l=i;
				flag=1;	
			}
			day=1;		
		}
		temlast=tem;
	}
	if(flag==0) cout<<"1 "<<n<<endl;
	else cout<<l-ansday<<" "<<l-1<<endl;
}                       