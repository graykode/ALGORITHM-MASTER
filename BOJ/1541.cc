#include<bits/stdc++.h>
using namespace std;
int main() {
	string s, temp = ""; cin >> s;
	long long ans = 0;
	int pos = 0;
	for (; pos <= s.length(); pos++) {
		if (pos == s.length() || s[pos] == '-') {
			ans += stoi(temp.c_str());
			temp = "";
			break;
		}else if (s[pos] == '+') {
			ans += stoi(temp.c_str());
			temp = "";
		}
		else temp += s[pos];
	}
	pos++;
	long long cnt = 0;
	for (; pos <= s.length(); pos++) {
		if (pos == s.length() || s[pos] == '-') {
			cnt += stoi(temp.c_str());
			ans -= cnt;
			temp = "";
			cnt = 0;
		}
		else if (s[pos] == '+') {
			cnt += stoi(temp.c_str());
			temp = "";
		}
		else temp += s[pos];
	}
	cout << ans;
}
