#include<bits/stdc++.h>
using namespace std;
int main() {
	long long n; cin >> n;
	long long i = 1, j = 0;
	for (; i < n; i *= 3, j++) {}
	for (long long loop = 1; loop < (1 << (j + 1)); loop++) {
		long long sum = 0;
		for (long long i = 0; i < (j + 1); i++) {
			if ((1 << i) & loop) {
				sum += (long long)pow(3, i);
			}
		}
		if (sum > n) break;
		if (sum == n) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}
