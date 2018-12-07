#include <bits/stdc++.h>
using namespace std;
int a[1001], g[1001];
bool c[1001];
bool go(int here, int group){
	c[here] = true;
	g[here] = group;
	if(g[a[here]] == g[here])
		return true;
	if(!c[a[here]])
		return go(a[here], group);
	return false;
}
int main() {
	int cnt = 0;
	int t; cin >> t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(g,0,sizeof(g));
		memset(c,false,sizeof(c));
		int n; cin >> n;
		for(int i=1; i<=n; i++) cin >> a[i];
		int ans = 0;
		for(int i=1; i<=n; i++){
			if(!c[i] && go(i, ++cnt)){
				ans++;
			}
		}
		cout << ans << endl;
	}
}
