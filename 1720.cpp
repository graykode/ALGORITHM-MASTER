#include<bits/stdc++.h>
using namespace std;
long long d[31];
long long go(int n){
	if(n == 1) return 1;
	if(n == 2) return 3;
	if(d[n]) return d[n];
	return d[n] = 2*go(n-2) + go(n-1);
}
int main(){
	int n; cin >> n;
	if(n <= 2) cout << go(n);
	else
		if(n%2 == 0) cout << (go(n) + 2*go((n-2)/2) + go(n/2))/2;
		else cout << (go(n) + go(n/2))/2;
}
