#include<bits/stdc++.h>
using namespace std;
long long a[4000000];
long long tree[4000000];
int n, m, k;
long long sum(int i) {
	long long ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}
void update(int i, long long diff) {
	while (i <= n) {
		tree[i] += diff;
		i += (i & -i);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(i, a[i]);
	}
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
			update(index, diff);
		}
		else if(command == 2) {
			int left, right;
			cin >> left >> right;
			cout << sum(right) - sum(left - 1) << "\n";
		}
	}
}
