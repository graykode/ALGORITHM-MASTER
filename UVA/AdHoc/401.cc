#include<bits/stdc++.h>
using namespace std;
map<char, char> m;
bool isPalindrome(string s) {
	string rs = s;
	reverse(rs.begin(), rs.end());
	if (rs == s) return true;
	return false;
}
int main() {
	m['A'] = 'A';
	m['E'] = '3';
	m['H'] = 'H';
	m['I'] = 'I';
	m['J'] = 'L';
	m['L'] = 'J';
	m['M'] = 'M';
	m['O'] = 'O';
	m['S'] = '2';
	m['T'] = 'T';
	m['U'] = 'U';
	m['V'] = 'V';
	m['W'] = 'W';
	m['X'] = 'X';
	m['Y'] = 'Y';
	m['Z'] = '5';
	m['1'] = '1';
	m['2'] = 'S';
	m['3'] = 'E';
	m['5'] = 'Z';
	m['8'] = '8';

	string s;
	while (cin >> s) {
		bool isP = isPalindrome(s);
		string ms = s;
		for (int i = 0; i < s.length(); i++) {
			ms[i] = m[s[i]];
		}
		reverse(ms.begin(), ms.end());
		bool isM = false;
		if (ms == s) isM = true;
		if (isP && isM)
			cout << s << " -- is a mirrored palindrome." << endl;
		else if(!isP && isM)
			cout << s << " -- is a mirrored string." << endl;
		else if (isP && !isM)
			cout << s << " -- is a regular palindrome." << endl;
		else cout << s << " -- is not a palindrome." << endl;
		cout << endl;
	}
}
