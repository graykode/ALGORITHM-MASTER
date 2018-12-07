#include<bits/stdc++.h>
using namespace std;
map<int, vector<int>> m;
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x, color; cin >> x >> color;
		m[color].push_back(x);
	}
	long long sum = 0;
	for (map<int, vector<int>>::iterator iter = m.begin(); iter != m.end(); iter++) {
		sort(m[iter->first].begin(), m[iter->first].end());
		for (int i = 0; i < m[iter->first].size(); i++) {
			if (i == 0) {
				sum += (m[iter->first][i + 1] - m[iter->first][i]);
			}
			else if (i == m[iter->first].size() - 1) {
				sum += (m[iter->first][i] - m[iter->first][i - 1]);
			}
			else {
				sum += min((m[iter->first][i] - m[iter->first][i - 1]), (m[iter->first][i + 1] - m[iter->first][i]));
			}
		}
	}
	cout << sum << endl;
}
