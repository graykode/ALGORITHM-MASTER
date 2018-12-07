#include<bits/stdc++.h>
using namespace std;
struct state{
	int pos, cnt;
};
bool c[200001];
int main() {
	int n, k; cin >> n >> k;
	queue<state> q;
	q.push({n,0});
	c[n] = true;
	while (!q.empty()) {
		auto here = q.front();
		q.pop();
		int pos = here.pos;
		int cnt = here.cnt;
		if (pos == k) {
			cout << cnt;
			return 0;
		}
		if (pos + 1 <= 200000 && !c[pos + 1]){
			q.push({ pos + 1,cnt + 1 });
			c[pos + 1] = true;
		}
		if (0 <= pos - 1 && !c[pos - 1]) {
			q.push({ pos - 1,cnt + 1 });
			c[pos - 1] = true;
		}
		if (pos * 2 <= 200000 && !c[pos * 2]) {
			q.push({ pos * 2 ,cnt + 1 });
			c[pos * 2] = true;
		}
	}
}
