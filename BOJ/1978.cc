#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;
unsigned char sieve[(MAX + 7) / 8 + 1];
bool isPrime(int k) {
	return sieve[k >> 3] & (1 << (k & 7));
}
void setComposite(int k) {
	sieve[k >> 3] &= ~(1 << (k & 7));
}
int main() {
	memset(sieve, 255, sizeof(sieve));
	setComposite(0), setComposite(1);
	for (int i = 2; i <= sqrt(MAX); i++)
		if (isPrime(i))
			for (int j = i * i; j <= MAX; j+=i)
				setComposite(j);
	int n, ans = 0; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (isPrime(x)) ans++;
	}
	cout << ans;
}
