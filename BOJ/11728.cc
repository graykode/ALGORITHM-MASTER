#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int> result;
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		result.push_back(x);
	}
	for (int i = 0; i < m; i++) {
		int x; scanf("%d", &x);
		result.push_back(x);
	}
	sort(result.begin(), result.end());
	for (int v : result) cout << v << " ";
}
