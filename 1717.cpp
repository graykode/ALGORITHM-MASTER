#include<bits/stdc++.h>
using namespace std;
class UnionFind {
private:
	vector<int> p, rank;
public:
	UnionFind(int n) {
		rank.assign(n + 1, 0);
		p.assign(n + 1, 0);
		for (int i = 0; i <= n; i++)
			p[i] = i;
	}
	int findSet(int i) {
		return p[i] == i ? i : p[i] = findSet(p[i]);
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void UnionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
			}
			else {
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	UnionFind u(n);
	while (m--) {
		int w, x, y;
		cin >> w >> x >> y;
		if (w == 0)
			u.UnionSet(x, y);
		else {
			x = u.findSet(x);
			y = u.findSet(y);
			if (x == y)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}
