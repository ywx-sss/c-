#include<bits/stdc++.h>
using namespace std;
int main()
{
    string c1,a1;
    cin>>a1;
	int a[5005]={}, c[5005]={};
	int lena=a1.size(),lenc=lena*2;
	for (int i=0 ; i<lena; i++) {
		a[lena-i] = a1[i] - '0';
	}
	for (int i = 1; i <= lena; i++) {
		for (int j = 1; j <= lena; j++) {
			c[i + j - 1] += a[i] * a[j];
			c[i + j] += c[i + j - 1] / 10;
			c[i + j - 1] %= 10;
		}
	}
	while (lenc > 1 && c[lenc] == 0) lenc--;
	while (lenc >= 1) c1 += c[lenc--] + '0';
	cout<< c1.erase(0,c1.size()-a1.size())<<endl<<a1;
}
