#include<bits/stdc++.h>
using namespace std;
int main() {
    string t,biao[13]={"1","2","3","4","5","6","7","8","9","10","11","12","13"};
    int n,a[13]={-50,-2,-3,-4,-5,-6,-7,-8,-9,-10,-20,-30,-40};
    while(1){
    	int flag1=0,ans[5]={0};
        for(int i=1;i<=4;i++){
    	    cin>>n;
    	    int flag2=0,flag3=0,flag4=0,flag5=0;
    	    if(n!=0){
			    flag1=1;
			}
    	    for(int j=1;j<=n;j++){
    	    	cin>>t;
    	    	switch(t[0]){
    	    		case 'H':{
    	    			t.erase(0, 1);
		                for(int j=0;j<=12;j++){
    		                if(biao[j]==t)ans[i]+=a[j];
		                }
				        flag2++;
						break;
					}
					case 'S':{
						ans[i]-=100;
				        flag3=1;
						break;
					}
					case 'D':{
						ans[i]+=100;
				        flag4=1;
						break;
					}
					case 'C':{
						flag5=1;
						break;
					}
				}
			}
			if(flag2==13){
				if(flag3==1&&flag4==1){
					ans[i]+=194+500;
				}
				else ans[i]+=194+200;
			}
			if(flag5==1){
				if(flag2==0&&flag3==0&&flag4==0){
					ans[i]+=50;
				}
				else ans[i]*=2;
			}
	    }
	    if(flag1==0)return 0;
	    else {
	    	if(ans[1]!=0)cout<<showpos<<ans[1];
	    	else cout<<"0";
	    	for(int i=2;i<=4;i++){
	    		if(ans[i]!=0)cout<<showpos<<" "<<ans[i];
	    		else cout<<" 0";
			}
			cout<<endl;
		}
	}
}  