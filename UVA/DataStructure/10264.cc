#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; 
	while (cin >> n) {
		vector<int> a;
		for (int edge = 0; edge < 1 << n; edge++) {
			int x; cin >> x;
			a.push_back(x);
		}
		vector<int> potencies;
		for (int edge = 0; edge < 1 << n; edge++) {
			int sum = 0;
			for (int i = 0; i < n; i++) {
				int index = edge ^ (1 << i);
				sum += a[index];
			}
			potencies.push_back(sum);
		}
		int ans = 0;
		for (int edge = 0; edge < 1 << n; edge++) {
			for (int i = 0; i < n; i++) {
				int index = edge ^ (1 << i);
				ans = max(ans, potencies[edge] + potencies[index]);
			}
		}
		cout << ans << endl;
	}
}
