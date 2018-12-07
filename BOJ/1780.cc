#include<bits/stdc++.h>
using namespace std;
int a[2188][2188];
int x, y, z;
bool isSame(int r, int c, int s) {
	int mone = 0, zero = 0, one = 0;
	for (int i = r; i < r + s; i++)
		for (int j = c; j < c + s; j++) {
			if (a[i][j] == -1) mone++;
			if (a[i][j] == 0) zero++;
			if (a[i][j] == 1) one++;
		}
	if (mone > 0 && zero > 0) return false;
	if (zero > 0 && one > 0) return false;
	if (mone > 0 && one > 0) return false;
	else return true;
}
void go(int r, int c, int s) {
	if(isSame(r, c, s)) {
		if (a[r][c] == -1) x++;
		if (a[r][c] == 0) y++;
		if (a[r][c] == 1) z++;
		return;
	}
	int news = s / 3;
	for (int i = r; i < r + s; i += news)
		for (int j = c; j < c + s; j += news) {
			if (isSame(i, j, news)) {
				if (a[i][j] == -1) x++;
				if (a[i][j] == 0) y++;
				if (a[i][j] == 1) z++;
			}
			else go(i, j, news);
		}
}
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	go(1, 1, n);
	cout << x << "\n" << y << "\n" << z;
}
