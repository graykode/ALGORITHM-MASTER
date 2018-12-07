#include<bits/stdc++.h>
using namespace std;
struct bar{
	int s,e;
};
int main(){
	vector<bar> b;
	vector<int> layer;
	string a; cin >> a;
	stack<pair<char,int>> s;
	for(int i=0; i<a.length(); i++){
		if(a[i] == '('){
			s.push(make_pair('(',i));
		}else if(a[i] == ')'){
			if(!s.empty() && s.top().first == '('){
				if(abs(s.top().second - i) == 1) layer.push_back(i);
				else b.push_back({s.top().second, i});
				s.pop();
			}
			else s.push(make_pair(')',i));
		}
	}
	int ans = 0;
	for(int i=0; i<b.size(); i++){
		int temp = 0;
		for(int j=0; j<layer.size(); j++){
			if(layer[j] < b[i].s) continue;
			else if(b[i].s <= layer[j] && layer[j] <= b[i].e) temp++;
			else if(b[i].e < layer[j]) break;
		}
		ans += temp+1;
	}
	cout << ans;
}
