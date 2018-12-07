#include<bits/stdc++.h>
using namespace std;
string s;
int mod = 1000000;
int d[5001];
int go(int pos){
	if(pos == s.length()) return 1;
	if(d[pos]) return d[pos];
	int x = (int)(s[pos]-'0');
	int y = 10*x + (int)(s[pos+1]-'0');
	if(1 <= x && x <= '9')
		d[pos] += go(pos+1)%mod;
	if(pos != s.length()-1 && 10 <= y && y <= 26)
		d[pos] += go(pos+2)%mod;
	return d[pos]%mod;
}
int main(){
	cin >> s;
	cout << go(0)%mod;
}
