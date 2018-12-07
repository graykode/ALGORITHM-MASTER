#include<bits/stdc++.h>
using namespace std;
pair<int,int> coor(int size, int p) {
	int r, c;
	r = c = (size + 1) / 2;
	int start = 1, nextstart = 2, index = 1, len = 1;
	while (true) {
		if (index % 2 == 0) {
			start = 1 + (index / 2) * (index / 2);
			nextstart = 1 + ((index + 2) / 2)*((index + 2) / 2 - 1);
			if (p < nextstart) break;
			if (index % 4 == 2) c -= len;
			if (index % 4 == 0) c += len;

			len++;
		}else{
			start = 1 + ((index + 1) / 2)*((index + 1) / 2 - 1);
			nextstart = 1 + ((index + 1) / 2)*((index + 1) / 2);
			if (p < nextstart) break;
			if (index % 4 == 1) r -= len;
			if (index % 4 == 3) r += len;
		}
		index++;
	}

	if (index % 4 == 2) c -= (p - start);
	if (index % 4 == 0) c += (p - start);
	if (index % 4 == 1) r -= (p - start);
	if (index % 4 == 3) r += (p - start);

	return make_pair(size - r + 1, c);	
}
int main() {

	while (true) {
		int size, p; cin >> size >> p;
		if (!size && !p) return 0;
		auto a = coor(size, p);
		printf("Line = %d, column = %d.\n", a.first, a.second);
	}
}
