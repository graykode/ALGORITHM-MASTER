#include<bits/stdc++.h>
using namespace std;
struct point {
	long long high;
	long long index;
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		long long area = 0;
		stack<point> left;
		int n; cin >> n;
		if (!n) break;
		for (long long i = 1; i <= n + 1; i++) {
			long long x;
			if (i == n + 1) x = -1;
			else cin >> x;

			while (!left.empty() && left.top().high > x) {
				auto front = left.top();
				left.pop();
				if (left.empty()) area = max(area, front.high * (i - 1));
				else area = max(area, front.high * (i - left.top().index - 1));
			}

			left.push({ x,i });
		}
		cout << area << "\n";
	}
}
