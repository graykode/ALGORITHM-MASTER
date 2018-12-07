#include<bits/stdc++.h>
using namespace std;
int main(){
	queue<int> q;
	int n, m; cin >> n >> m;
	for(int i=1; i<=n; i++)
		q.push(i);
	int mod = 1;
	cout <<"<";
	while(!q.empty()){
		if(mod == m){
			if(q.size() == 1) cout << q.front()<<">";
			else cout << q.front()<<", ";
			q.pop();
			mod = 0;
		}else{
			int f = q.front();
			q.pop();
			q.push(f);
		}
		mod++;
	}
}
