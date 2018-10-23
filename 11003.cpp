#include<bits/stdc++.h>
using namespace std;
struct point {
	int value;
	int index;
};
int a[5000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	deque<point> dq;
	int n, l; cin >> n >> l;
	for (int i = 0; i < n; i++) {

		int x; cin >> x;
		while (!dq.empty() && dq.front().index <= i - l) {
			dq.pop_front();
		}

		while (!dq.empty() && dq.back().value > x) {
			dq.pop_back();
		}
		dq.push_back({ x,i });
		cout << dq.front().value << " ";
	}
}
