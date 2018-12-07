#include<bits/stdc++.h>
using namespace std;
int main() {
	while (true) {
		int n; cin >> n;
		if (n == 0) break;
		vector<int> a;
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			a.push_back(x);
		}
		vector<int> b;
		for (int i = 1; i <= n - 6; i++) b.push_back(0);
		for (int i = 1; i <= 6; i++) b.push_back(1);
		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());
		do {
			for (int i = 0; i < n; i++)
				if (b[i]) cout << a[i] << " ";
			cout << "\n";
		} while (prev_permutation(b.begin(), b.end()));
		cout << "\n";
	}
}
