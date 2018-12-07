#include<bits/stdc++.h>
using namespace std;
struct meeting{
	int start, end;
};
bool cmp(const meeting a, const meeting b){
	if(a.end < b.end) return true;
	else if(a.end == b.end){
		return a.start < b.start;
	}
	return false;
}
int main(){
	vector<meeting> v;
	int n; cin >> n;
	for(int i=0; i<n; i++){
		int s,e; cin >> s >> e;
		v.push_back({s,e});
	}
	sort(v.begin(),v.end(), cmp);
	int start = v[0].end;
	int ans = 1;
	for(int i=1; i<n; i++){
		if(v[i].start >= start){
			start = v[i].end;
			ans++;
		}
	}
	cout << ans;
}
