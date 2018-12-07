#include<bits/stdc++.h>
using namespace std;
long long a[4000000];
long long tree[4000000];
long long lazy[4000000];
long long init(int node, int left ,int right) {
	if (left == right)
		return tree[node] = a[left];
	else 
		return tree[node] = init(2 * node, left, (left + right) / 2) 
		+ init(2 * node + 1, (left + right) / 2 + 1, right);
}
void update_lazy(int node, int left, int right) {
	if (lazy[node] != 0) {
		tree[node] += (right - left + 1) * lazy[node];
		// 리프 노드가 아니면
		if (left != right) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update_range(int node, int left, int right, int i, int j, long long diff) {
	update_lazy(node, left, right);
	if (right < i || j < left) return;
	// 파란색
	if (i <= left && right <= j) {
		// 현재 node는 바로 더하고
		tree[node] += (right - left + 1) * diff;
		// 리프 노드가 아니면 lazy를 남겨둔다.
		if (left != right) {
			lazy[2 * node] += diff;
			lazy[2 * node + 1] += diff;
		}
		return ;
	}
	// 초록색
	update_range(2 * node, left, (left + right) / 2, i, j, diff);
	update_range(2 * node + 1, (left + right) / 2 + 1, right, i, j, diff);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
long long query(int node, int left, int right, int i, int j) {
	update_lazy(node, left, right);
	if (right < i || j < left)
		return 0;
	if (i <= left && right <= j)
		return tree[node];
	return query(2 * node, left, (left + right) / 2, i, j) 
		+ query(2 * node + 1, (left + right) / 2 + 1, right, i, j);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int len = m + k;
	init(1, 1, n);
	while (len--) {
		int command;
		cin >> command;
		if (command == 1) {
			int left, right;
			long long diff;
			cin >> left >> right >> diff;
			update_range(1, 1, n, left, right, diff);
		}
		else if (command == 2) {
			int left, right;
			cin >> left >> right;
			cout << query(1, 1, n, left, right) << "\n";
		}
	}
}
