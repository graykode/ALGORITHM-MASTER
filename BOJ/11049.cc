#include<bits/stdc++.h>
using namespace std;
int n, a[501][2];
long long d[501][501];
long long go(int s, int e){
	if(s == e) return 0;
	if(s+1 == e) return a[s][0]*a[s][1]*a[e][1];
	if(d[s][e] != -1) return d[s][e];
	d[s][e] = 987654321;
	for(int i=s; i<e; i++)
		d[s][e] = min(d[s][e], go(s,i) + go(i+1,e) + a[s][0]*a[i][1]*a[e][1]);
	return d[s][e];
}
int main(){
	memset(d,-1,sizeof(d));
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i][0] >> a[i][1];
	cout << go(1,n);
}
