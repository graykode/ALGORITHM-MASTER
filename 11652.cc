#include<bits/stdc++.h>
using namespace std;
map<long long, long long , greater<long long>> m;
vector<long long> v;
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		long long x; cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < v.size(); i++)
		m[v[i]]++;
	map<long long, long long>::iterator mi;
	long long temp = 0, ans;
	for (mi = m.begin(); mi != m.end(); mi++) {
		if (temp <= mi->second) {
			temp = mi->second;
			ans = mi->first;
		}
	}
	cout << ans;
}
