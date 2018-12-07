#include<bits/stdc++.h>
using namespace std;
int group[20001];
vector<vector<int>> a;
void dfs(int cur, int par, int id) {
	group[cur] = id;
	id = (id == 1 ? 2 : 1);
	for (int next : a[cur]) {
		if (cur == par) continue;
		if (group[next] == 0)
			dfs(next, cur, id);
	}
}
int main() {
	int t; cin >> t;
	while (t--) {
		a.clear();
		int v, e; cin >> v >> e;
		memset(group, 0, sizeof(group));
		a.resize(v + 1);
		for (int i = 0; i < e; i++) {
			int x, y; cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		for (int i = 1; i <= v; i++)
			if (!group[i]) dfs(i, -1, 1);
		bool flag = true;
		for (int i = 1; i <= v; i++) {
			for (int next : a[i]) {
				if (group[i] == group[next]) {
					flag = false;
					break;
				}
			}
		}
		if (!flag) cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}
}
