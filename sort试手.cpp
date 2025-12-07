#include <bits/stdc++.h>
using namespace std;
double pi=3.1415926535897932;
typedef struct{
	double x,y,r;
}circle;
double overlap(circle cir1,circle cir2){
	double l=sqrt((cir1.x-cir2.x)*(cir1.x-cir2.x)+(cir1.y-cir2.y)*(cir1.x-cir2.x));
	if(l>=(cir1.r+cir2.r))return 0;
	if(l<=abs(cir1.r-cir2.r)){
		if(cir1.r>=cir2.r)return cir2.r*cir2.r*pi;
		else return cir1.r*cir1.r*pi;
	}
    else
    {   double angle1,angle2,s1,s2,s3,s4;
        angle1=acos((l*l+cir1.r*cir1.r-cir2.r*cir2.r)/(2*l*cir1.r));
        angle2=acos((l*l+cir2.r*cir2.r-cir1.r*cir1.r)/(2*l*cir2.r));
        s1=angle1*cir1.r*cir1.r;
        s2=angle2*cir2.r*cir2.r;
        s3=cir1.r*cir1.r*sin(angle1)*cos(angle1);
        s4=cir2.r*cir2.r*sin(angle2)*cos(angle2);
        return s1+s2-(s3+s4);
        }
}
int main(){
	int n;
	double an,ans=0;
	circle cir[1005];
	cin>>n;
	cin>>cir[1].x>>cir[1].y>>cir[1].r;
	ans+=cir[1].r*cir[1].r*pi;
	for(int i=2;i<=n;i++){
		cin>>cir[i].x>>cir[i].y>>cir[i].r;
		an=cir[i].r*cir[i].r*pi;
		int j=i-1;
		while(j!=0){
			an-=overlap(cir[j],cir[i]);
			j--;
		}
		ans+=an;
		cout<<an<<endl;
	}
	cout<<ans;
	return 0;
}