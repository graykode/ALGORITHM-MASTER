#include<bits/stdc++.h>
using namespace std;
char small[1001][1001], big[1001][1001];
int N, n;
int compare() {
	int cnt = 0;
	for (int i = 1; i <= N-n+1; i++) {
		for (int j = 1; j <= N-n+1; j++) {
			bool flag = true;
			for (int x = 1; x <= n; x++) {
				for (int y = 1; y <= n; y++)
					if (big[i + x - 1][j + y - 1] != small[x][y])
						flag = false;
			}
			if (flag) cnt++;
		}
	}
	return cnt;
}
void rotate() {
	char temp[1001][1001];

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			temp[i][j] = small[i][j];

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			temp[i][j] = small[n - j + 1][i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			small[i][j] = temp[i][j];
}
int main() {
	while (true) {
		cin >> N >> n;
		if (!N && !n) break;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				scanf(" %c", &big[i][j]);

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf(" %c", &small[i][j]);

		cout << compare() << " ";
		rotate();
		cout << compare() << " ";
		rotate();
		cout << compare() << " ";
		rotate();
		cout << compare() << "\n";
	}
}
