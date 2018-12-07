#include<bits/stdc++.h>
using namespace std;
int a[101], d[10001];
int n,k;
int go(int left, int pos){
	if(left == 0) return 1;
	if(d[left]) return d[left];
	d[left] = 100000;
	for(int i=pos; i<=n; i++){
		if(left-a[i] >= 0)
			d[left] = min(d[left], go(left-a[i], i)+1);
	}
	return d[left];
}
int main(){
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	int ans = go(k,1);
	if(ans == 100000) cout << -1;
	else cout << ans-1;
}
