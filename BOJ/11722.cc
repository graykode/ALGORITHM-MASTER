#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	int n; cin >> n;
	for(int i=0;i<n; i++) cin >> a[i];
	reverse(a,a+n);
	vector<int> v;
	v.push_back(INT32_MIN);
	for(int i=0; i<n; i++){
		if(v.back() < a[i])
			v.push_back(a[i]);
		else{
			auto it = lower_bound(v.begin(), v.end(), a[i]);
			*it = a[i];
		}
	}
	cout << v.size()-1;
}
