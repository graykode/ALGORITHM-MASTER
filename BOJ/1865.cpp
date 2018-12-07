#include<bits/stdc++.h>
using namespace std;
struct edge {
	int to, weight;
};
int d[501];
int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, w;
		cin >> n >> m >> w;
		vector<edge> a[501];
		memset(d, 0, sizeof(d));
		for (int i = 0; i < m; i++) {
			int from, to, weight;
			cin >> from >> to >> weight;
			a[from].push_back({ to,weight });
			a[to].push_back({ from,weight });
		}
		for (int i = 0; i < w; i++) {
			int from, to, weight;
			cin >> from >> to >> weight;
			a[from].push_back({ to, -weight });
		}
		bool negative = false;
		// 벨만포드 알고리즘 시작
		for (int loop = 1; loop <= n; loop++) {
			// 모든 정점을 돌며
			bool flag = false;
			for (int v = 1; v <= n; v++) {
				// 정점에 연결된 모든 간선을 돈다
				for (int e = 0; e < a[v].size(); e++) {
					int next = a[v][e].to;
					int weight = a[v][e].weight;
					if (d[next] > d[v] + weight) {
						flag = true;
						d[next] = d[v] + weight;
						if (loop == n)
							negative = true; 
					}
				}
			}
			if (!flag) break;
		}

		if (negative) cout << "YES\n";
		else cout << "NO\n";
	}
}
