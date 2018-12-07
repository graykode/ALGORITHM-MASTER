#include<bits/stdc++.h>
using namespace std;
int gcd(int l, int k) { return k ? gcd(k, l%k) : l; }
int lcm(int l, int k) {	return l * (k / gcd(l,k)); }
int main() {
	int t; cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		bool flag = false;
		int l = lcm(m, n);
		for (int i = 0; i <= l / n; i++) {
			int left = n * i + y - x;
			if (!(left % m)) {
				flag = true;
				cout << n * i + y << "\n";
				break;
			}
		}
		if (!flag) cout << -1 << "\n";
	}
}
