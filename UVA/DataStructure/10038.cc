#include<bits/stdc++.h>
using namespace std;
bool flag[3011];
int main() {
	int n;
	while (cin >> n) {
		memset(flag, false, sizeof(flag));
		int a[3011];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			if(abs(a[i] - a[i + 1]) < n)
				flag[abs(a[i] - a[i + 1])] = true;
		bool is = true;
		for (int i = 1; i < n; i++)
			if (!flag[i]) is = false;
		is ? cout << "Jolly\n" : cout << "Not jolly\n";
	}
}
