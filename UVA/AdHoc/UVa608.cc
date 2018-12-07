#include<bits/stdc++.h>
using namespace std;
map<char, bool> flag;
map<char, bool> used;
struct judge{
	string left, right, result;
};
int main() {
	int t; cin >> t;
	while (t--) {
		used.clear();
		flag.clear();
		vector<judge> v;
		for (int loop = 0; loop < 3; loop++) {
			string left, right, result;
			cin >> left >> right >> result;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < left.length(); j++)
					used[left[j]] = true;
				for (int j = 0; j < right.length(); j++)
					used[right[j]] = true;
			}
			v.push_back({ left, right, result });
		}
		int num = 0;
		// even은 그 줄에 위조지폐가 완벽히 없다는 것은 자명하다.
		for (int i = 0; i < 3; i++) {
			if (v[i].result == "even") {
				for (int j = 0; j < v[i].left.length(); j++) {
					flag[v[i].left[j]] = true;
				}
				for (int j = 0; j < v[i].right.length(); j++) {
					flag[v[i].right[j]] = true;
				}
				num++;
			}
		}
		if (num == 3) {
			for (int money = 0; money < 12; money++)
				if (!used[(char)(money + 'A')]) {
					printf("%c is the counterfeit coin and it is heavy.\n", 'A' + money);
				}
		}

		

		// 완전탐색
		for (int money = 0; money < 12; money++) {
			if (flag[(char)(money + 'A')]) continue;
			if (!used[(char)(money + 'A')]) continue;

			// Is heavy?
			bool isAns = true;
			for (int i = 0; i < 3; i++) {
				if (v[i].result != "even") {
					int l = 0, r = 0;

					for (int j = 0; j < v[i].left.length(); j++) {
						if (v[i].left[j] != (char)('A' + money)) l += 20;
						else l += 0;
					}

					for (int j = 0; j < v[i].right.length(); j++) {
						if (v[i].right[j] != (char)('A' + money)) r += 20;
						else r += 0;
					}

					if (v[i].result == "up" && l <= r) isAns = false;
					if (v[i].result == "down" && l >= r) isAns = false;
				}
			}
			if (isAns) {
				printf("%c is the counterfeit coin and it is light.\n", (char)(money + 'A'));
				break;
			}

			isAns = true;
			// Is light?
			for (int i = 0; i < 3; i++) {
				if (v[i].result != "even") {
					int l = 0, r = 0;

					for (int j = 0; j < v[i].left.length(); j++) {
						if (v[i].left[j] != (char)('A' + money)) l += 20;
						else l += 2000;
					}

					for (int j = 0; j < v[i].right.length(); j++) {
						if (v[i].right[j] != (char)('A' + money)) r += 20;
						else r += 2000;
					}

					if (v[i].result == "up" && l <= r) isAns = false;
					if (v[i].result == "down" && l >= r) isAns = false;
				}
			}
			if (isAns) {
				printf("%c is the counterfeit coin and it is heavy.\n", (char)(money + 'A'));
				break;
			}
		}
	}
}
