#include<bits/stdc++.h>
using namespace std;
pair<int,int> coor(int size, int p) {
	int r, c, len = 1, start = 1;
	r = c = (size + 1)/2;
	bool flag = true;
	
	// while문 쓸 때 이런식으로 다음에 갈 조건을 미리 넣어주면 
	// 새로운 변수를 안만들고 while문을 나올 수 있다.
	while (start + len <= p) {
		
		if (len%2 == 1) 
			flag ? r -= len : c -= len;
		else
			flag ? r += len : c += len;

		start = start + len;
		flag = flag ? false : len++, true;
	}
	if (len % 2 == 1)
		flag ? r -= (p - start) : c -= (p - start);
	else
		flag ? r += (p - start) : c += (p - start);

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
