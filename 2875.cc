#include<bits/stdc++.h>
using namespace std;
int main() {
	int m, n, k; cin >> m >> n >> k;
	int team = 0, outteam = 0;
	for (int i = 1; i <= n; i++) {
		if (2 * i <= m) team++;
	}
	outteam = m + n - team * 3;
	if (outteam < k) {
		k -= outteam;
		int c = 3 * team - k;
		while (c % 3 != 0) c--;
		cout << c / 3;
	}
	else if (outteam >= k) cout << team;
}
