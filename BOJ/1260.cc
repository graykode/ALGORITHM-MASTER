#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
bool check[10001];
void go(int here){
	check[here] = true;
	cout << here <<" ";
	for(auto next : a[here]){
		if(!check[next]){
			go(next);	
		}
	}
}
int main(){
	int n,m,v;
	cin >> n >> m >> v;
	a.resize(n+1);
	for(int i=0; i<m; i++){
		int x,y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=0; i<a.size(); i++){
		sort(a[i].begin(), a[i].end());
	}
	go(v); cout << endl;
	queue<int> q;
	memset(check,false, sizeof(check));
	q.push(v);
	check[v] = true;
	cout << v <<" ";
	while(!q.empty()){
		int here = q.front();
		q.pop();
		for(int next : a[here])
			if(!check[next]){
				cout << next<<" ";
				check[next] = true;
				q.push(next);
			}
	}
}
