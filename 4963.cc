#include<bits/stdc++.h>
using namespace std;
int w, h, a[51][51];
bool c[51][51];
int dx[] = { 1,-1,0,0,1,1,-1,-1 };
int dy[] = { 0,0,1,-1,1,-1,-1,1 };
int main() {
	while (true) {
		memset(c, false, sizeof(c));
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				cin >> a[i][j];
		queue<pair<int, int>> q;
		int ans = 0;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++) {
				if (a[i][j] == 1 && !c[i][j]) {
					ans++;
					q.push(make_pair(i, j));
					c[i][j] = true;
					while (!q.empty()) {
						auto here = q.front();
						q.pop();
						for (int k = 0; k < 8; k++) {
							int nx = here.first + dx[k];
							int ny = here.second + dy[k];
							if (1 <= nx && nx <= h && 1 <= ny && ny <= w && !c[nx][ny] && a[nx][ny] == 1) {
								q.push(make_pair(nx, ny));
								c[nx][ny] = true;
							}
						}
					}
				}
			}
		cout << ans << "\n";
	}
}
