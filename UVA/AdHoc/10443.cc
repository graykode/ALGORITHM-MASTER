#include<bits/stdc++.h>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int main() {
	int t; cin >> t;
	while (t--) {
		int r, c, day; cin >> r >> c >> day;
		char a[101][101];
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				scanf(" %1c", &a[i][j]);
		for (int d = 0; d < day; d++) {
			char na[101][101];
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					na[i][j] = a[i][j];

			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					for (int k = 0; k < 4; k++) {
						int x = i + dx[k];
						int y = j + dy[k];
						if (0 <= x && x < r && 0 <= y && y < c) {
							if (a[i][j] == 'S' && a[x][y] == 'R')
								na[i][j] = 'R';
							else if(a[i][j] == 'P' && a[x][y] == 'S')
								na[i][j] = 'S';
							else if (a[i][j] == 'R' && a[x][y] == 'P')
								na[i][j] = 'P';
						}
					}

			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					a[i][j] = na[i][j];

		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				printf("%c", a[i][j]);
			puts("");
		}
		puts("");
	}
}
