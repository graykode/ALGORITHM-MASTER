#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
bool check[1001];
int main(){
	int n,m; cin >> n >> m;
	v.resize(n+1);
	for(int i=0; i<m; i++){
		int x,y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int ans = 0;
	for(int i=1; i<=n; i++){
		if(!check[i]){
			queue<int> q;
			check[i] = true;
			q.push(i);
			while(!q.empty()){
				int here = q.front();
				q.pop();
				for(int next : v[here]){
					if(!check[next]){
						check[next] = true;
						q.push(next);
					}
				}
			}
			ans++;
		}
	}
	cout << ans;
}
