#include<bits/stdc++.h>
using namespace std;
map<string, bool> a;
int main(){
	int n,m; cin>>n>>m;
	for(int i=0; i<n; i++){
		string s; cin >> s;
		a[s] = true;
	}
	vector<string> v;
	for(int i=0; i <m; i++){
		string s; cin >> s;
		if(a[s]) v.push_back(s);
	}
	sort(v.begin(), v.end());
	cout << v.size()<<endl;
	for(int i=0; i<v.size(); i++)
		cout << v[i] <<endl;
}
