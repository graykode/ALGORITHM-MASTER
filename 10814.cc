#include<bits/stdc++.h>
using namespace std;
bool cmp(const pair<int, string> a, const pair<int, string> b){
	return a.first < b.first;
}
int main(){
	ios::sync_with_stdio(false);
	vector<pair<int, string>> v;
	int n; cin >> n;
	for(int i=0; i<n; i++){
		int age; string name;
		cin >> age >> name;
		v.push_back(make_pair(age,name));
	}
	stable_sort(v.begin(), v.end(), cmp);
	for(int i=0; i<n; i++)
		cout << v[i].first <<" "<<v[i].second <<"\n";
}
