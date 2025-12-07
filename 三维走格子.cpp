#include<iostream>
using namespace std;
typedef long long ll;
ll C(ll n,ll m){
    if(m==0 || m == n) return 1;
    return C(n-1,m)+C(n-1,m-1);
}
int main()
{
    int x,y,z;
    ll ans=0;
    cin>>x>>y>>z;
    ans+=C(x+y+z,x)*C(y+z,y);
    cout<<ans<<endl;
    return 0;
}