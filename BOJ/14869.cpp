#include<bits/stdc++.h>
using namespace std;
int a[3001][3001], before[3001], sum[3001][3001], d[3001][3001];
int m, n, s, e, t;

struct vacademy {
	int value, academy;
} mn[3001][3]; // 해당 lecture를 들을 때 d[...][lecture]의 최솟값

struct vlecture {
	int value; // d(k,h) - s(i,h)값
	int lecture;
};


deque<vlecture> dq[3001]; // 해당 academy을 오기전에 j-e <= h <= j-s에 해당되는 이전 dp값.
// 모든 j-e <= h <= j-s 구간을 담고 있는 것이 아닌, window sliding 기법으로 dp 자료를 담음

// 해당 academy을 오기전에 그 이전 academy의 a[academy][lecutre]의 가장 작은 3개.
int get_minimum3(int academy, int lecture) {
	if (mn[lecture][0].academy != academy && mn[lecture][0].academy != before[academy])
		return mn[lecture][0].value;
	else if (mn[lecture][1].academy != academy && mn[lecture][1].academy != before[academy])
		return mn[lecture][1].value;
	return mn[lecture][2].value;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> s >> e >> t;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		cin >> before[i];
	for (int i = 1; i <= n; i++) {
		sum[i][1] = a[i][1];
		for (int j = 2; j <= m; j++)
			sum[i][j] = sum[i][j - 1] + a[i][j];
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			mn[i][0] = mn[i][1] = mn[i][2] = { (int)1e9, j };
			d[j][i] = 1e9;
			if (i < s) 
				continue;

			if (i >= s) {
				int value = get_minimum3(j, i - s) - sum[j][i - s];
				while (!dq[j].empty() && value <= dq[j].back().value)
					dq[j].pop_back();
				dq[j].push_back({ value, i - s });
			}

			while (!dq[j].empty() && dq[j].front().lecture < i - e)
				dq[j].pop_front();

			if (!dq[j].empty())
				d[j][i] = dq[j].front().value + t + sum[j][i];
		}
		for (int j = 1; j <= n; j++) {
			if (d[j][i] < 1e9) {
				int value = d[j][i];

				// mn도 0,1,2 오름차순으로 정렬
				if (value < mn[i][0].value) {
					mn[i][2] = mn[i][1];
					mn[i][1] = mn[i][0];
					mn[i][0] = {value, j};
				}
				else if (value < mn[i][1].value) {
					mn[i][2] = mn[i][1];
					mn[i][1] = { value, j };
				}
				else if (value < mn[i][2].value) {
					mn[i][2] = { value, j };
				}
			}
		}
	}


	int ans = 1e9;
	for (int i = 1; i <= n; i++) {
		// 마지막 d[...][m]는 어디서 왔는지?
		for (int j = m - e; j < m; j++) {
			int value = get_minimum3(i, j);
			if (value == 1e9) continue;
			ans = min(ans, value + sum[i][m] - sum[i][j]);
		}
	}
	cout << ans;
}
