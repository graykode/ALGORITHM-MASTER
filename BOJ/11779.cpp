#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int inf = 987654321;
struct edge {
	int to, weight;
};
vector<edge> a[1011];
bool visited[1011];
int parent[1011];
long long d[1011];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		a[from].push_back({ to, weight });
	}
	
	int start, end;
	cin >> start >> end;
	
	for (int i = 0; i <= n; i++)
		d[i] = inf;
	d[start] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		pii front = pq.top();
		pq.pop();

		int now = front.second;
		if (visited[now]) continue;
		visited[now] = true;
		
		for (int i = 0; i < a[now].size(); i++) {
			int next = a[now][i].to;
			int weight = a[now][i].weight;
			if (d[next] > d[now] + weight) {
				d[next] = d[now] + weight;
				pq.push(make_pair(d[next], next));
				
				// 여기서 만들어진 트리는 MST가 자명하다
				parent[next] = now;
			}
		}
	}
	cout << d[end] << "\n";
	
	stack<int> st;
	int here = end;
	while (here) {
		st.push(here);
		here = parent[here];
	}
	cout << st.size() << "\n";
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}
