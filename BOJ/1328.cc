#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long d[101][101][101];
long long go(int n, int l, int r){
	if(r == 0 || l == 0 || n == 0) return 0;
	if(d[n][l][r] != -1) return d[n][l][r];
	d[n][l][r] = 0;
	return d[n][l][r] = (go(n-1,l-1,r)%mod + ((n-2)*go(n-1,l,r))%mod + go(n-1,l,r-1)%mod)%mod;
}
int main(){
	int n,l,r; cin >> n >> l >> r;
	memset(d,-1,sizeof(d));
	d[1][1][1] = 1;
	cout << go(n,l,r)%mod;
}
