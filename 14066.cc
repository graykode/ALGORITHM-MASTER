#include<bits/stdc++.h>
using namespace std;
int h[51][51];
char a[10001][10001];
string arr[7] = {
	"+---+",
	"|   |/",
	"|   | +",
	"+---+ |",
	"./   /|",
	"..+---+"
};
int main() {
	int r, c, mh = -1; cin >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			cin >> h[i][j];
			mh = max(mh, h[i][j]);
		}

	int width = 7 + 4 * (c - 1) + 2 * (r - 1);
	int height = 6 + 3 * (mh - 1) + 2 * (r - 1);

	for (int i = 1; i <= height; i++)
		for (int j = 1; j <= width; j++)
			a[i][j] = '.';
	

	for (int i = 1; i <= r; i++) {
		int extra = 2 * (r - i);
		for (int j = 1; j <= c; j++) {
			for (int k = 1; k <= h[i][j]; k++) {
				int nr = 1 + 3 * (k - 1) + extra;
				int nc = 1 + 4 * (j - 1) + extra;
				for (int x = 0; x < 6; x++) {
					for (int y = 0; y < arr[x].length(); y++) {
						if (arr[x][y] != '.')
							a[nr + x][nc + y] = arr[x][y];

					}
				}
			}
		}
	}

	for (int i = height; i > 0; i--) {
		bool print = false;
		for (int j = 1; j <= width; j++) {
			if (a[i][j] != '.')
				print = true;
		}
		if (print) {
			for (int j = 1; j <= width; j++)
				cout << a[i][j];
			cout << endl;
		}
	}
}
