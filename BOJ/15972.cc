#include<bits/stdc++.h>
using namespace std;
int n, m, h;
int idx[1050][1050];
int ans[1000500];
// first : next node, second : next2node weight
vector<pair<int,int>> a[1000500];
int main() {

	scanf("%d%d%d", &n, &m, &h);

	int timer = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			idx[i][j] = ++timer;

	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= m; j++) {
			int w; scanf("%d", &w);
			if (w == -1) continue;
			int x = idx[i][j], y = idx[i - 1][j];
			a[x].push_back(make_pair(y, w));
			a[y].push_back(make_pair(x, w));
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m + 1; j++) {
			int w; scanf("%d", &w);
			if (w == -1) continue;
			int x = idx[i][j], y = idx[i][j - 1];
			a[x].push_back(make_pair(y, w));
			a[y].push_back(make_pair(x, w));
		}
	}
	
	ans[0] = 0;
	for (int i = 1; i <= n * m; i++)
		ans[i] = h;

	// first : high, second : number of node
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Edge;
	Edge.push(make_pair(0, 0));
	while (!Edge.empty()) {
		auto NowEdge = Edge.top();
		Edge.pop();

		int NowHopeWeight = NowEdge.first;
		int NowNode = NowEdge.second;
		
		//if (ans[NowNode] != NowHopeWeight) continue;

		for (auto NextEdge : a[NowNode]) {
			int newHigh = max(NextEdge.second, NowHopeWeight);
			if (ans[NextEdge.first] > newHigh) {
				ans[NextEdge.first] = newHigh;
				Edge.push({ ans[NextEdge.first] , NextEdge.first});
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= n * m; i++)
		result += ans[i];
	printf("%d\n", result);
}
