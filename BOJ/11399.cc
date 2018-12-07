#include<bits/stdc++.h>
using namespace std;
int d[1001];
int main() {
	int n; cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		if (i == 0) d[i] = v[i];
		else d[i] = d[i - 1] + v[i];
	}
	long long sum = 0;
	for (int i = 0; i < n; i++) sum += d[i];
	cout << sum;
}
