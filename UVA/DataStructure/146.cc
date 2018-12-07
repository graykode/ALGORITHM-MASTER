#include<bits/stdc++.h>
using namespace std;
int main() {
	while (true) {
		string s; cin >> s;
		if (s == "#") break;
		string sorted = s;
		sort(sorted.begin(), sorted.end());
		next_permutation(s.begin(), s.end());
		if (s == sorted) cout << "No Successor" << endl;
		else cout << s << endl;
	}
}
