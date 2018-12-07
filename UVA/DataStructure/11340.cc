#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		map<char, int> m;
		int k; cin >> k;
		for (int i = 0; i < k; i++) {
			char key; int value;
			cin >> key >> value;
			m[key] = value;
		}
		int line;
		long long sum = 0; cin >> line;
		cin.ignore();
		for (int l = 0; l < line; l++) {
			string s; getline(cin, s);
			for (int i = 0; i < s.length(); i++)
				sum += m[s[i]];
		}
		printf("%d.%02d$\n", (int)(sum / 100), (int)(sum % 100));
	}
}
