#include<bits/stdc++.h>
using namespace std;
bitset<1000001> bit;
bool Confict(int start, int end) {
	for (int i = start; i < end; i++) {
		if (bit[i]) return true;
		else bit.set(i);
	}
	return false;
}
bool isconfict = false;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		bit.reset();
		int n, m; cin >> n >> m;
		if (!n && !m) break;
		isconfict = false;
		while (n--) {
			int start, end;
			cin >> start >> end;
			if (!isconfict) {
				isconfict = Confict(start, end);
			}
		}
		while (m--) {
			int start, end, repeat;
			cin >> start >> end >> repeat;
			while (!isconfict && start < 1000000) {
				isconfict = Confict(start, min(end, 1000000));
				start += repeat;
				end += repeat;
			}
		}
		if (isconfict)
			cout << "CONFLICT" << "\n";
		else
			cout << "NO CONFLICT" << "\n";
	}
}
