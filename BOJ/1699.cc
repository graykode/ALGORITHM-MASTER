#include<bits/stdc++.h>
using namespace std;
int n, d[100001];
int go(int left){
	if(left == n) return 0;
	if(d[left]) return d[left];
	d[left] = 9999999;
	for(int i=1; i<=sqrt(n-left); i++){
		d[left] = min(d[left], go(left+i*i)+1);
	}
	return d[left];
}
int main(){
	cin >> n;
	cout << go(0);
}
