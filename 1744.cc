#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int> plus, minus;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if(x > 0) plus.push_back(x);
		else if (x <= 0) minus.push_back(x);
	}
	sort(plus.begin(), plus.end());
	reverse(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());
	long long ans = 0;
	if (minus.size() % 2 == 0) {
		for (int i = 0; i < minus.size(); i+=2) {
			ans += minus[i] * minus[i + 1];
		}
	}
	else {
		ans += minus.back();
		for (int i = 0; i < minus.size() - 1; i += 2) {
			ans += minus[i] * minus[i + 1];
		}
	}
	if (plus.size() % 2 == 0) {
		for (int i = 0; i < plus.size(); i += 2) {
			ans += max(plus[i] * plus[i + 1], plus[i] + plus[i + 1]);
		}
	}
	else {
		ans += plus.back();
		for (int i = 0; i < plus.size() - 1; i += 2) {
			ans += max(plus[i] * plus[i + 1], plus[i] + plus[i + 1]);
		}
	}
	cout << ans;
}
