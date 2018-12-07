#include <bits/stdc++.h>
using namespace std;
int c[1000001];
int a,p;
int multi(int val){
	if(val == 0) return 0;
	else return multi(val/10) + pow(val%10,p);
}
void go(int here){
	if(c[here] != 2){
		c[here]++;
		int next = multi(here);
		go(next);
	}
}
int main() {
	cin >> a >> p;
	go(a);
	int ans = 0;
	for(int i=1; i<=1000000; i++){
		if(c[i] == 1) ans ++;
	}
	cout << ans;
}
