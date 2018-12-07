#include<bits/stdc++.h>
using namespace std;
int a[101][101];
long long d[101][101];
int dx[] = {1,0};
int dy[] = {0,1};
int n;
long long go(int x, int y){
	if(x == n && y == n) return 1;
	if(d[x][y]) return d[x][y];
	for(int k=0;k<2; k++){
		int nx = x + dx[k] * a[x][y];
		int ny = y + dy[k] * a[x][y];
		if((1 <= nx && nx <= n && 1 <= ny && ny <= n && a[nx][ny] != 0) || (a[nx][ny] == 0 && nx == n && ny == n))
			d[x][y] += go(nx,ny);
	}
	return d[x][y];
}
int main(){
	cin >> n ;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin >> a[i][j];
	cout << go(1,1);
}
