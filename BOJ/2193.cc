#include<bits/stdc++.h>
using namespace std;
int n;
long long d[91][3];
long long go(int cur, int layer){
	if(layer == n) return 1;
	if(d[layer][cur]) return d[layer][cur];
	long long cnt = 0;
	if(cur == 0) cnt += go(0,layer+1) + go(1,layer+1);
	else if(cur == 1) cnt += go(0, layer+1);
	return d[layer][cur] = cnt;
}
int main(){
	cin >> n;
	cout << go(1,1);
}
