#include<bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s;
	long long sum = 0;
	bool flag = false;
	for (int i = 0; i < s.length(); i++) {
		sum += (int)(s[i] - '0');
		if ((int)(s[i] - '0') == 0) flag = true;
	}
	if (flag && sum % 3 == 0) {
		sort(s.begin(), s.end());
		reverse(s.begin(), s.end());
		cout << s;
	}
	else cout << -1;
}
