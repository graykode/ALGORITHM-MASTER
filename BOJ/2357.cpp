#include<bits/stdc++.h>
using namespace std;
const int maximum = 400111;
int a[maximum];
int mintree[maximum];
int maxtree[maximum];
void mininit(int node, int start, int end) {
	if (start == end)
		mintree[node] = a[start];
	else {
		mininit(node * 2, start, (start + end) / 2);
		mininit(node * 2 + 1, (start + end) / 2 + 1, end);
		mintree[node] = min(mintree[node * 2], mintree[node * 2 + 1]);
	}
}
void maxinit(int node, int start, int end) {
	if (start == end)
		maxtree[node] = a[start];
	else {
		maxinit(node * 2, start, (start + end) / 2);
		maxinit(node * 2 + 1, (start + end) / 2 + 1, end);
		maxtree[node] = max(maxtree[node * 2], maxtree[node * 2 + 1]);
	}
}
int minquery(int node, int start, int end, int i, int j) {
	// 1. [i,j]와 [start, end]가 겹치지 않는 경우
	if (end < i || j < start)
		return -1;
	// 2. [i,j]가 [start,end]를 완전히 포함하는 경우
	if (i <= start && end <= j)
		return mintree[node];
	// 1번 2번 의외 경우
	int m1 = minquery(2 * node, start, (start + end) / 2, i, j);
	int m2 = minquery(2 * node + 1, (start + end) / 2 + 1, end, i, j);

	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else return min(m1, m2);
}

int maxquery(int node, int start, int end, int i, int j) {
	if (end < i || j < start)
		return -1;
	if (i <= start && end <= j)
		return maxtree[node];
	int m1 = maxquery(2 * node, start, (start + end) / 2, i, j);
	int m2 = maxquery(2 * node + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else return max(m1,m2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	mininit(1, 1, n), maxinit(1, 1, n);
	for (int i = 0; i < m; i++) {
		int a, b; 
		cin >> a >> b;
		cout << minquery(1, 1, n, a, b) << " " << maxquery(1, 1, n, a, b) << "\n";
	}
}
