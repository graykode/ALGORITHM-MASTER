#include<bits/stdc++.h>
using namespace std;
int d[51][250001], n, a[51];
int go(int pos, int diff){
	if(diff > 250000) return -555555;
	if(pos == n+1){
		if(diff == 0) return 0;
		return -555555;
	}
	if(d[pos][diff] != -1) return d[pos][diff];
	d[pos][diff] = go(pos+1,diff);
	d[pos][diff] = max(d[pos][diff], go(pos+1,diff+a[pos]));
	if(a[pos] > diff)
		d[pos][diff] = max(d[pos][diff], go(pos+1,a[pos]-diff)+diff);
	else
		d[pos][diff] = max(d[pos][diff], go(pos+1,diff-a[pos])+a[pos]);
	return d[pos][diff];
}
int main(){
	memset(d,-1,sizeof(d));
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	int ans = go(1,0);
	if(ans != 0) cout << ans;
	else cout << -1;
}
