#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> a;
long long d[100001];
bool check[100001];
bool isfind = false;
int n, first, second;
vector<int> path;
void dfs(int here, long long distance) {
	for (pair<int, int> nNode : a[here]) {
		int next = nNode.first;
		if (!check[next] && !isfind) {
			check[next] = true;
			d[next] = distance + nNode.second;
			path.push_back(nNode.second);
			if (next == second) {
				isfind = true;
				break;
			}
			dfs(next, distance + nNode.second);
			if(!isfind)
				path.pop_back();
		}
	}
}
int main() {
	long long dis = 0;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> first >> second;
	a.resize(n + 1);
	for (int i = 1; i <= n - 1; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		a[from].push_back(make_pair(to, weight));
		a[to].push_back(make_pair(from, weight));
	}
	check[first] = true;
	d[first] = 0;
	dfs(first, 0);
	if (path.size()  < 2)
		cout << 0;
	else {
		sort(path.begin(), path.end());
		path.pop_back();
		for (int i = 0; i < path.size(); i++) {
			dis += path[i];
		}
		cout << dis;
	}
	
}
