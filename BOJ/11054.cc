#include<bits/stdc++.h>
using namespace std;
int a[1000], u[1000], d[1000];
map<int, int> mu, md;
int main(){
	int n, cnt=0; cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	vector<int> v;
	v.push_back(INT32_MIN);
	u[0] = 0;
	for(int i=1; i<=n; i++){
		if(v.back() < a[i]){
			u[i] = ++cnt;
			v.push_back(a[i]);
		}
		else{
			auto it = lower_bound(v.begin(), v.end(), a[i]);
			u[i] = mu[v[it-v.begin()]];
			*it = a[i];	
		}
		mu[a[i]] = u[i];
	}
	v.clear();
	d[0] = 0, cnt = 0;
	reverse(a+1,a+n+1);
	v.push_back(INT32_MIN);
	for(int i=1; i<=n; i++){
		if(v.back() < a[i]){
			d[i] = ++cnt;
			v.push_back(a[i]);
		}
		else{
			auto it = lower_bound(v.begin(), v.end(), a[i]);
			d[i] = md[v[it-v.begin()]];
			*it = a[i];	
		}
		md[a[i]] = d[i];
	}
	reverse(d+1,d+n+1);
	int ans = 0;
	for(int i=1; i<=n; i++)
		ans = max(ans, d[i]+u[i]-1);
	cout << ans;
}
