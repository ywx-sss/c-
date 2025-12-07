#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;
int ConverM2T(string str,int m){
    int number = 0; //该数在10进制下的表示
    for (int i = 0; i < str.size(); ++i) {
        number *= m;
        number += Char2Int(str[i]);
    }
    return number;
}
 
char Int2Char(int target){
    if (target < 10) {
        return target + '0';
    } else {
        return target - 10 + 'a';
    }
}
//十进制转换成N进制
void ConvertT2N(int number,int n){
    stack<char> s;
    while (number) {
        s.push(Int2Char(number % n));
        number /= n;
    }
    if (s.empty()) {    //当输入是0时，输出也是0
        printf("0");
    }
    while (!s.empty()) {
        printf("%c", s.top());
        s.pop();
    }
    printf("\n");
}
 
int main(){
    int n,flag=0;
	string s;char ans[10005];
	cin>>n;
	getline(cin,s);
	for(int i=2;i<=16;i++){
		if(n%i==0&&(n/i)%i==0){
		    cout<<i<<" ";
			ConvertT2N(n,i);
		    flag=1;
		    break;
	    }
	}
	if(flag==0)cout<<"impossible";
    return 0;
    return  0;
}
