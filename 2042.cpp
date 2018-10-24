#include<bits/stdc++.h>
using namespace std;
const int maximum = 4000000;
long long a[maximum];
long long tree[maximum];
long long init(int node, int left, int right) {
	if (left == right) return tree[node] = a[right];
	else return  tree[node] = init(2 * node, left, (left + right) / 2) + init(2 * node + 1, (left + right) / 2 + 1, right);
}

long long query(int node, int left, int right, int i, int j) {
	if (right < i || j < left) return 0;
	if (i <= left && right <= j) return tree[node];
	return query(2 * node, left, (left + right) / 2, i, j) + query(2 * node + 1, (left + right) / 2 + 1, right, i, j);
}

void update(int node, int left, int right, int index, long long value) {
	if (left <= index && index <= right) {
		tree[node] += value;
		if (left != right) {
			update(2 * node, left, (left + right) / 2, index, value);
			update(2 * node + 1, (left + right) / 2 + 1, right, index, value);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	init(1, 1, n);

	int len = m + k;
	while (len--) {
		int command;
		cin >> command;
		if (command == 1) {
			int index;
			long long value;
			cin >> index >> value;
			long long diff = value - a[index];
			a[index] = value;
			update(1, 1, n, index, diff);
		}
		else if (command == 2) {
			int left, right;
			cin >> left >> right;
			cout << query(1, 1, n, left, right) << "\n";
		}
	}
}
