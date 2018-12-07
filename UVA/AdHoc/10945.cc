#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	while (true) {
		getline(cin , s);
		if (s == "DONE") break;
		string ns = "";
		for (int i = 0; i < s.length(); i++) {
			if ('A' <= s[i] && s[i] <= 'Z')
				ns += tolower(s[i]);
			if ('a' <= s[i] && s[i] <= 'z')
				ns += s[i];
		}
		string rs = ns;
		reverse(rs.begin(), rs.end());
		if (rs == ns)
			cout << "You won't be eaten!" << endl;
		else cout << "Uh oh.." << endl;
	}
}
