#include <bits/stdc++.h>
using namespace std;
int main(){
    int set,n,s,q,time=0,num=0,sum,nnum[1005];
    int point=1;
    queue<int> nb[105];
    stack<int> car;
    cin>>set;
    for(int k=1;k<=set;k++){
    	time=0;
    	cin>>n>>s>>q;
    	for(int i=1;i<=n;i++){
    		cin>>nnum[i];
    		for(int j=1;j<=nnum[i];j++){
    			cin>>sum;
    			nb[i].push(sum);
			}
			num+=nnum[i];
		}
		while(num>0){
			cout<<num<<" "<<time<<" "<<car.size()<<" "<<point<<" "<<nb[point].size()<<endl;
		    while(!car.empty()){
		    	if(car.top()==point){
					car.pop();
					num--;
				}
				else{
					if(nb[point].size()==q)break;
					else{
						nb[point].push(car.top());
						car.pop();
					}
				}
				time++;
			}
			while(car.size()<s){
				if(!nb[point].empty()){
					car.push(nb[point].front());
					nb[point].pop();
				}
				else{
					break;
				}
				time++;
			}
			time+=2;
			cout<<num<<" "<<time<<" "<<car.size()<<" "<<point<<" "<<nb[point].size()<<endl;
			point++;
			if(point>n)point-=n;
			
		}
		cout<<time-2<<endl;
	}	
	return 0;
}