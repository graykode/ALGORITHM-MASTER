#include<bits/stdc++.h>
using namespace std;
int main() {
	while (true) {
		int m, n; cin >> m >> n;
		if (!m && !n) break;
		if (m < 3 || n < 3) {
			if(min(m, n) == 0)
				printf("%d knights may be placed on a %d row %d column board.\n", 0, m, n);
			else if (min(m, n) == 1)
				printf("%d knights may be placed on a %d row %d column board.\n", max(m, n), m, n);
			else if (min(m, n) == 2) {
				int index = max(m, n);
				while ((index - 1) % 4 != 0)
					index--;
				if((max(m, n) - 1)%4 == 0)
					printf("%d knights may be placed on a %d row %d column board.\n", 2 * ((index + 3) / 2 - 1), m, n);
				else
					printf("%d knights may be placed on a %d row %d column board.\n", 2 * ((index + 3) / 2 - 1) + 2, m, n);
			}
		}
		else printf("%d knights may be placed on a %d row %d column board.\n", ((m + 1) / 2) * ((n + 1) / 2) + (m / 2) * (n / 2), m, n);
	}
}
