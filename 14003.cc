#include<bits/stdc++.h>
using namespace std;
int d[1000001], a[1000001];
map<int, int> m;
int main(){
	int n, cnt=0; cin >> n;
	vector<int> v;
	v.push_back(INT32_MIN);
	d[0] = 0;
	for(int i=1; i<=n; i++){
		int x; cin >> x;
		a[i] = x;
		if(v.back() < x){
			d[i] = ++cnt;
			v.push_back(x);
		}
		else{
			auto it = lower_bound(v.begin(), v.end(), x);
			d[i] = m[v[it-v.begin()]];
			*it = x;	
		}
		m[x] = d[i];
	}
	int start = -1, high = -1;
	for(int i=1; i<=n; i++){
		if(high < d[i])
			high = d[i], start = i;
	}
	vector<int> ans;
	for(int i=start; i>=1; i--){
		if(high == d[i]){
			ans.push_back(a[i]);
			high--;
		}
	}
	reverse(ans.begin(),ans.end());
	cout << v.size()-1 << endl;
	for(int i=0; i<ans.size(); i++)
		cout << ans[i] <<" ";
}
