#include<bits/stdc++.h>
using namespace std;
int n, a[10001], d[10001][3];
int go(int p, int s){
	if(p == n) return 0;
	if(d[p][s] != -1) return d[p][s];
	if(s == 2) d[p][s] = go(p+1,0);
	else
		d[p][s]= max(go(p+1,s+1)+a[p+1],go(p+1,0));
	
	return d[p][s];
}
int main(){
	cin >> n;
	memset(d,-1,sizeof(d));
	for(int i=1; i<=n; i++) cin >> a[i];
	cout << go(0,0);
}
