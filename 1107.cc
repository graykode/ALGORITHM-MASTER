#include<bits/stdc++.h>
using namespace std;
int n,m;
map<int,bool> v;
int go(char mode){
	bool flag = false;
	int start = n;
	string s;
	while(!flag){
		if(!(0 <= start && start <= 1000000)) return INT32_MAX;
		s = to_string(start);
		bool f = true;
		for(int i=0; i<s.length(); i++){
			if(v[(int)(s[i]-'0')]) f = false;
		}
		if(mode == 'p') start++;
		else if(mode == 'm') start--;
		if(f) flag = true;
	}
	return abs(stoi(s.c_str()) - n) + s.length();
}
int main(){
	cin >> n >> m;
	for(int i=1; i<=m; i++){
		int x; cin >> x;
		v[x] = true;
	}
	int first, second;
	if(m == 10)
		first = second = INT32_MAX;
	else {
		first = go('p');
		second = go('m');
	}
	cout << min(abs(n-100), min(first, second));
}
