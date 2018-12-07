#include<bits/stdc++.h>
using namespace std;
int a[3][100001], d[3][100001];
int go(int p, int s){
	if(p == 0) return 0;
	if(d[s][p] != -1) return d[s][p];
	if(s != 1) d[s][p] = max(d[s][p], go(p-1,1)+a[2][p]);
	if(s != 2) d[s][p] = max(d[s][p], go(p-1,2)+a[1][p]);
	return d[s][p] = max(d[s][p], go(p-1,0));
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		memset(a,0,sizeof(a));
		memset(d,-1,sizeof(d));
		for(int i=1; i<=n; i++) cin >> a[1][i];
		for(int i=1; i<=n; i++) cin >> a[2][i];
		cout << go(n,0) << endl;
	}
}
