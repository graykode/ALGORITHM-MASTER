/*
   dijkstra with priority_queue
*/
#include<bits/stdc++.h>
using namespace std;

struct Edge {
	int cost;
	int to;
	Edge(int _cost, int _to) {
		cost = _cost;
		to = _to;
	}
};

vector<Edge> a[20001];
int dist[20001];
int inf = 1000000000;
bool check[20001];
int main() {
	int v, e, k;
	cin >> v >> e >> k;
	for (int i = 0; i < e; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		a[from].push_back(Edge(to, weight));
	}
	for (int i = 1; i <= v; i++) {
		dist[i] = inf;
	}
	dist[k] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, k));
	while (!q.empty()) {
		pair<int, int> front = q.top();
		q.pop();
		int here = front.second;
		if (check[here]) {
			continue;
		}
		for (int i = 0; i < a[here].size; i++) {
			int next = a[here][i].to;
			if (dist[next] > dist[here] + a[here][i].cost) {
				dist[next] = dist[here] + a[here][i].cost;
				q.push(make_pair(-dist[next], next));
			}
		}
	}
}
