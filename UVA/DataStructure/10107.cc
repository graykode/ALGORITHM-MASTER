#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int> a;
	int x;
	while (cin >> x) {
		a.push_back(x);
		sort(a.begin(), a.end());
		if (a.size() % 2 == 0) 
			cout << (a[(a.size()-1) / 2] + a[(a.size() - 1) / 2 + 1])/2 << "\n";
		else 
			cout << a[((a.size() - 1) + 1) / 2] << "\n";
	}

}
