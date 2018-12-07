#include<bits/stdc++.h>
using namespace std;
int tree[4000000]; // 인덱스 넘버를 담는다.
int a[4000000];
int n;
void init(int node, int left, int right) {
	if (right == left)
		// a배열의 값을 저장하는 것이 아니라 인덱스 넘버를 저장한다.
		tree[node] = left;
	else {
		init(2 * node, left, (left + right) / 2);
		init(2 * node + 1, (left + right) / 2 + 1, right);
		if (a[tree[2 * node]] <= a[tree[2 * node + 1]])
			tree[node] = tree[2 * node];
		else
			tree[node] = tree[2 * node + 1];
	}
}
int query(int node, int left, int right, int i, int j) {
	if (right < i || j < left) return -1;
	if (i <= left && right <= j) return tree[node];
	int m1 = query(2 * node, left, (left + right) / 2, i, j);
	int m2 = query(2 * node + 1, (left + right) / 2 + 1, right, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else {
		if (a[m1] <= a[m2]) return m1;
		else return m2;
	}
}
long long largest(int left, int right) {
	int m = query(1, 1, n, left, right);
	long long area = (long long)(right - left + 1) * (long long)(a[m]);

	// 분할 정복
	if (left <= m - 1) {
		long long temp = largest(left, m - 1);
		area = max(area, temp);
	}
	if (m + 1 <= right) {
		long long temp = largest(m + 1, right);
		area = max(area, temp);
	}
	return area;
}
int main() {
	while (true) {
		memset(tree, 0, sizeof(tree));
		memset(a, 0, sizeof(a));
		cin >> n;
		if (!n) break;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		init(1, 1, n);
		cout << largest(1, n) << "\n";
	}
}
