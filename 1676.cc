#include<bits/stdc++.h>
using namespace std;
int two, five;
void go(int k) {
	for (int i = 2; i <= k; i++) {
		if (k%i == 0)
			while (k%i == 0) {
				if (i == 2) two++;
				if (i == 5) five++;
				k /= i;
			}
	}
}
int main() {
	int n; cin >> n;
	for (int i = 2; i <= n; i++) go(i);
	cout << min(two, five);
}
