#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    int flag[85]={0};
    getline(cin,s);
    getline(cin,t);
    for(int i=0;i<s.size();i++){
        for(int j=0;j<t.size();j++){
            if(s[i]==t[j]){
                 flag[i]=1;
                 break;
            }
        }
    }
    for(int i=0;i<s.size();i++){
         if(flag[i]==0)cout<<s[i];   
    }
    cout<<endl;
    return 0;
}