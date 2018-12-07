#include<bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s;
	int n; cin >> n;
	deque<char> l, r;
	for (int i = 0; i < s.length(); i++)
		l.push_back(s[i]);
	while (n--) {
		string cmd; cin >> cmd;
		if (cmd == "L" && !l.empty()) {
			char f = l.back();
			l.pop_back();
			r.push_front(f);
		}
		else if (cmd == "D" && !r.empty()) {
			char f = r.front();
			r.pop_front();
			l.push_back(f);
		}
		else if (cmd == "B" && !l.empty()) {
			l.pop_back();
		}
		else if (cmd == "P") {
			char x; cin >> x;
			l.push_back(x);
		}
	}
	string ans = "";
	while (!l.empty()) {
		char f = l.front();
		l.pop_front();
		ans += f;
	}
	while (!r.empty()) {
		char f = r.front();
		r.pop_front();
		ans += f;
	}
	cout << ans;
}
