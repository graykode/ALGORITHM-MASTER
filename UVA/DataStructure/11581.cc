#include<bits/stdc++.h>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int main() {
	int t; cin >> t;
	while (t--) {
		int a[4][4], all = 0;
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++) {
				scanf("%1d", &a[i][j]);
				all += a[i][j];
			}

		if (!all) {
			cout << -1 << endl;
			continue;
		}

		int ans = 0, day = 0;
		while (true) {
			int cnt = 0;
			int temp[4][4];
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					int sum = 0;
					for (int k = 0; k < 4; k++) {
						int ni = i + dx[k];
						int nj = j + dy[k];
						if (1 <= ni && ni <= 3 && 1 <= nj && nj <= 3) {
							sum += a[ni][nj];
						}
					}
					temp[i][j] = sum % 2;
				}
			}

			for (int i = 1; i <= 3; i++)
				for (int j = 1; j <= 3; j++) {
					a[i][j] = temp[i][j];
					a[i][j] ? cnt++ : 0;
				}

			if (!cnt) {
				ans = day;
				break;
			}

			day++;
		}
		cout << ans << endl;
	}
}
