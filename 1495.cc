#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int a[101], d[1001][101];
int go(int now, int pos){
	if(pos == n){
		if(now+a[pos] <= m) return now+a[pos];
		if(0 <= now-a[pos]) return now-a[pos];
		return -1;
	}
	if(d[now][pos]) return d[now][pos];
	d[now][pos] = -1;
	if(now+a[pos] <= m)
		d[now][pos] = max(d[now][pos], go(now+a[pos],pos+1));
	if(0 <= now-a[pos])
		d[now][pos] = max(d[now][pos], go(now-a[pos],pos+1) );
	return d[now][pos];
}
int main(){
	cin >> n >> s >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	cout << go(s,1);
}
