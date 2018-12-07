#include<bits/stdc++.h>
using namespace std;
int go(int n, int k) {
	if (n >= k) return n - k;
	if (k % 2 == 0) return min(k - n, go(n, k / 2) + 1);
	else return min(go(n, k + 1), go(n, k - 1)) + 1;
}
int main() {
	int n, k; cin >> n >> k;
	if (n == 0) cout << 1 + go(1, k);
	else cout << go(n, k);
}
