#include<bits/stdc++.h>
using namespace std;
const int inf = -9999999;
int a[1001][1001], d[1001][1001];
int dx[] = {1,0,1};
int dy[] = {0,1,1};
int n,m;
int go(int x, int y){
	if(x == n && y == m) return a[x][y];
	if(d[x][y] != inf) return d[x][y];
	for(int k=0;k<3; k++){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(1 <= nx && nx <= n && 1 <= ny && ny <= m)
			d[x][y] = max(d[x][y], go(nx,ny) + a[x][y]);
	}
	return d[x][y];
}
int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++){
			d[i][j] = inf;
			cin >> a[i][j];
		}
	cout << go(1,1);
}
