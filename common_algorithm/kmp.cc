#include<bits/stdc++.h>
using namespace std;

vector<int> getpi(string b) {
	vector<int> pi;
	pi.resize(b.length());
	int j = 0;
	for (int i = 1; i < b.length(); i++) {
		while (j > 0 && b[i] != b[j])
			j = pi[j - 1];
		if (b[i] == b[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<bool> kmp(string a, string b) {
	vector<bool> res(a.length(), 0);
	vector<int> pi = getpi(b);

	int j = 0;
	for (int i = 0; i < a.length(); i++) {
		while (j > 0 && a[i] != b[j])
			j = pi[j - 1];
		if (a[i] == b[j]) {
			if (j == b.length() - 1) {
				res[i - b.length() + 1] = true;
				j = pi[j];
			}
			else j++;
		}
	}
	return res;
}
