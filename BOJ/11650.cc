#include<bits/stdc++.h>
using namespace std;
bool cmp(const pair<int,int> a, const pair<int,int> b){
	if(a.first < b.first) return true;
	else if(a.first == b.first)
		return a.second < b.second;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	vector<pair<int, int>> v;
	int n; cin >> n;
	for(int i=0; i<n; i++){
		int x,y; cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(), v.end(), cmp);
	for(int i=0; i<v.size(); i++)
		cout << v[i].first <<" "<<v[i].second<<"\n";
}
