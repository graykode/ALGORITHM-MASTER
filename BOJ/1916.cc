#include<bits/stdc++.h>
using namespace std;
struct Edge {
	int to, cost;
};
vector<vector<Edge>> a;
const int inf = 987654321;
bool check[1001];
int d[1001];
int main() {
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	a.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		a[from].push_back({ to,cost });
	}
	for (int i = 1; i <= n; i++)
		d[i] = inf;
	int start, end; cin >> start >> end;
	d[start] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, start));
	while (!q.empty()) {
		auto here = q.top();
		q.pop();
		if (check[here.second]) continue;
		check[here.second] = true;
		for (auto next : a[here.second]) {
			if (d[next.to] > d[here.second] + next.cost) {
				d[next.to] = d[here.second] + next.cost;
				q.push(make_pair(-d[next.to], next.to));
			}
		}
	}
	cout << d[end];
}
