#include<bits/stdc++.h>
using namespace std;
int a[101][11], wa[101], solve[101], tosolve[101], problem[11];
int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> wa[i];
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				problem[j]++;
				solve[i]++;
			}
		}
		tosolve[i] = wa[i] - solve[i];
	}
	for (int i = 1; i <= n; i++) {
		if (wa[i] == 0 || wa[i] == m) {
			cout << "NO";
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == -1) {
				if (tosolve[i] > 0 && problem[j] == 0) {
					a[i][j] = 1;
					tosolve[i]--;
					problem[j]++;
				}
				else a[i][j] = 0;
			}
		}
	}
	for (int j = 1; j <= m; j++) {
		bool flag = false;
		for (int i = 1; i <= n; i++) {
			if (a[i][j] == 1) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
