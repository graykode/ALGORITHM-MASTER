#include<bits/stdc++.h>
using namespace std;
int a[1001], d[1001][31];
int t,w;
int go(int pos, int move, int state){
	if(pos == 0) return 0;
	if(move == 0){
		return go(pos-1,move,state) + (a[pos-1] == state ? 1 : 0);
	}
	
	if(d[pos][move] != -1) return d[pos][move];
	d[pos][move] = 0;
	d[pos][move] = max(d[pos][move], go(pos-1,move,state) + (a[pos-1] == state ? 1 : 0));
	int nstate = (state == 1 ? 2 : 1);
	d[pos][move] = max(d[pos][move], go(pos-1,move-1,nstate) + (a[pos-1] == nstate ? 1 : 0));
	return d[pos][move];
}
int main(){
	cin >> t >> w;
	memset(d,-1,sizeof(d));
	for(int i=1; i<=t; i++) cin >> a[i];
	cout << go(t+1,w,1);
}
