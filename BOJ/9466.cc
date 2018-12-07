#include <bits/stdc++.h>
using namespace std;
int g[100001], a[100001];
bool check[100001], v[100001];
void go(int here, int group){
	if(group == g[here]){
		int fix = here;
		check[here] = true;
		here = a[here];
		while(here != fix){
			check[here] = true;
			here = a[here];
		}
	}
	v[here] = true;
	g[here] = group;
	if((!v[a[here]] || group == g[a[here]]) && !check[a[here]])
		go(a[here], group);
}
int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		memset(check,false, sizeof(check));
		memset(v,false,sizeof(v));
		memset(a,0,sizeof(a)), memset(g,0,sizeof(g));
		int n, cnt = 0, ans = 0; cin >> n;
		for(int i=1; i<=n; i++) cin >> a[i];
		for(int i=1; i<=n; i++)
			if(!v[i]) go(i, ++cnt);
		for(int i=1; i<=n; i++)
			if(!check[i]) ans++;
		cout << ans << endl;
	}
}
