#include<bits/stdc++.h>
using namespace std;
int n, a[26][26];
bool c[26][26];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int main() {
	queue<pair<int, int>> q;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			scanf("%1d", &a[i][j]);
	vector<int> many;
	int group = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 1 && !c[i][j]) {
				int cnt = 0;
				group++, cnt++;
				q.push(make_pair(i, j));
				c[i][j] = true;
				while (!q.empty()) {
					auto here = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = here.first + dx[k];
						int ny = here.second + dy[k];
						if (1 <= nx && nx <= n && 1 <= ny && ny <= n && !c[nx][ny] && a[nx][ny] == 1) {
							q.push(make_pair(nx, ny));
							c[nx][ny] = true;
							cnt++;
						}
					}
				}
				many.push_back(cnt);
			}
		}
	cout << group << "\n";
	sort(many.begin(), many.end());
	for (int t : many)
		cout << t << "\n";
}
