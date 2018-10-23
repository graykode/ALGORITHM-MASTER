#include<bits/stdc++.h>
using namespace std;
const int inf = 987654321;
long long a[1011][1011];
long long d[1011];
bool visited[1011];
int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = inf;
		}
	}

	for (int i = 0; i < m; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		if(a[from][to] > weight)
			a[from][to] = weight;
	}

	int start, end;
	cin >> start >> end;

	for (int i = 1; i <= n; i++)
		d[i] = inf;
	d[start] = 0;
	
	for (int loop = 1; loop <= n; loop++) {
		int minimum = inf;
		int index = -1;
		// 방문하지 않은 것 중에 dist가 가장 작은 것
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && minimum >= d[i]) {
				minimum = d[i];
				index = i;
			}
		} 
		visited[index] = true;
		for (int i = 1; i <= n; i++) {
			if (d[i] > d[index] + a[index][i]) {
				d[i] = d[index] + a[index][i];
			}
		}
	}
	cout << d[end]; 
}
