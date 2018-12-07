#include<bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s;
	if (s == "0") {
		cout << 0;
		return 0;
	}
	string ans = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') ans += "000";
		else if (s[i] == '1') ans += "001";
		else if (s[i] == '2') ans += "010";
		else if (s[i] == '3') ans += "011";
		else if (s[i] == '4') ans += "100";
		else if (s[i] == '5') ans += "101";
		else if (s[i] == '6') ans += "110";
		else if (s[i] == '7') ans += "111";
	}
	int start = 0;
	while (ans[start] == '0') start++;
	cout << ans.substr(start);
}
