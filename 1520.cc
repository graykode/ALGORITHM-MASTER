#include<bits/stdc++.h>
using namespace std;
int a[501][501], d[501][501];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n,m;
int go(int x, int y){
	if(x == n && y == m) return 1;
	if(d[x][y] != -1) return d[x][y];
	d[x][y] = 0;
	for(int k=0;k<4; k++){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(1 <= nx && nx <= n && 1 <= ny && ny <= m && a[x][y] > a[nx][ny])
			d[x][y] += go(nx,ny);
	}
	return d[x][y];
}
int main(){
	memset(d,-1,sizeof(d));
	cin >> n >> m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin >> a[i][j];
	cout << go(1,1);
}
