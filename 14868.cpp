#include<bits/stdc++.h>
using namespace std;
class UnionFind {
private:
	vector<int> p, rank;
public:
	UnionFind(int n) {
		p.assign(n + 1, 0);
		rank.assign(n + 1, 0);
		for (int i = 0; i <= n; i++)
			p[i] = i;
	}
	int Find(int i) {
		return p[i] == i ? i : p[i] = Find(p[i]);
	}
	void Union(int i, int j) {
		int x = Find(i), y = Find(j);
		if (x != y) {
			if (rank[x] > rank[y])
				p[y] = x;
			else {
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
};
bool visited[2001][2001];
int group[2001][2001];
queue<pair<int, int>> q, first;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	q.push({ 0, 0 });
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		visited[x][y] = true;
		q.push({ x, y });
		first.push({ x, y });
	}

	int timer = 0;
	for (int i = 1; i <= n; i++) {
		for(int j=1; j<=n; j++){
			group[i][j] = ++timer;
		}
	}

	int cnt = k;
	UnionFind init(n*n);
	// 처음에 모든 점이 인접해 있는가?
	while (!first.empty()) {
		auto front = first.front();
		first.pop();
		int x = front.first, y = front.second;

		for (int z = 0; z < 4; z++) {
			int nx = x + dx[z];
			int ny = y + dy[z];
			if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
				if (visited[nx][ny] && init.Find(group[x][y]) != init.Find(group[nx][ny])) {
					init.Union(group[x][y], group[nx][ny]);
					cnt--;
				}
			}
		}
	}
	if (cnt == 1) {
		cout << 0;
		return 0;
	}

	UnionFind u(n*n);
	int ans = 0;
	cnt = k;
	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		int x = front.first, y = front.second;
		if (x == 0 && y == 0) {
			if (cnt == 1) {
				cout << ans;
				return 0;
			}
			else {
				q.push({ 0, 0 });
				ans += 1;
				continue;
			}
		}
		

		for (int z = 0; z < 4; z++) {
			int nx = x + dx[z];
			int ny = y + dy[z];
			if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
				if (!visited[nx][ny]) {
					q.push({ nx,ny });
					visited[nx][ny] = true;
					group[nx][ny] = group[x][y];
					for (int zz = 0; zz < 4; zz++) {
						int nnx = nx + dx[zz];
						int nny = ny + dy[zz];
						if (1 <= nnx && nnx <= n && 1 <= nny && nny <= n) {
							if (visited[nnx][nny] && u.Find(group[nx][ny]) != u.Find(group[nnx][nny])) {
								u.Union(group[nx][ny], group[nnx][nny]);
								cnt--;
							}
						}
					}
				}
				// 원래 
				else if(visited[nx][ny] && u.Find(group[x][y]) != u.Find(group[nx][ny])){
					u.Union(group[x][y], group[nx][ny]);
					cnt--;
				}
			}
		}
	}
}
