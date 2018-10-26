#include<bits/stdc++.h>
using namespace std;
int coin[21];
int n, ans = 21*21;
void go(int row) {
	if (row == n + 1) {
		int total = 0;
		for (int i = 1; i <= (1 << (n-1)); i = i << 1) {
			int cnt = 0;
			for (int j = 1; j <= n; j++) {
				if (coin[j] & i) cnt++;
			}
			total += min(cnt, n - cnt);
		}
		ans = min(ans, total);
	}
	else {
		coin[row] = ~coin[row];
		go(row + 1);
		coin[row] = ~coin[row];
		go(row + 1);
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x = 1 << (n - 1);
		for (int j = 1; j <= n; j++) {
			char c; cin >> c;
			if (c == 'T') {
				coin[i] += x;
			}
			x = x >> 1;
		}
	}
	go(1);
	cout << ans;
}
 
