#include<bits/stdc++.h>
using namespace std;
int d[3][500];
int main() {
	while (true) {
		int m, n; cin >> m >> n;
		if (!m && !n) break;
		if (m < 3 || n < 3) {
			for (int i = 1; i <= max(m, n); i++)
				d[0][i] = 0;
			for (int i = 1; i <= max(m, n); i++)
				d[1][i] = i;
			int index = 0;
			for (int i = 1; i <= max(m, n); i++) {
				if ((i - 1) % 4 == 0) {
					d[2][i] = 2 * ((i + 3) / 2 - 1);
					index = i;
				}
				else {
					d[2][i] = 2 * ((index + 3) / 2 - 1) + 2;
				}
			}
			printf("%d knights may be placed on a %d row %d column board.\n", d[min(m,n)][max(m, n)], m, n);
		}
		else printf("%d knights may be placed on a %d row %d column board.\n", ((m + 1) / 2) * ((n + 1) / 2) + (m / 2) * (n / 2), m, n);
	}
}
