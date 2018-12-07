#include<iostream>
#define mod 10007
using namespace std;
int d[1001];
int main() {
	d[1] = 1, d[2] = 2;
	int n; cin >> n;
	for (int i = 3; i <= n; i++)
		d[i] = (d[i - 1] % mod + d[i - 2] % mod) % mod;
	cout << d[n] % mod;
}
