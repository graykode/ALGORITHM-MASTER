#include<bits/stdc++.h>
using namespace std;
int n, a[101];
long long d[101][21];
long long go(int pos, int sum){
	if(pos == n-1){
		if(sum == a[n]) return 1;
 		return 0;
	}
	if(d[pos][sum] != -1) return d[pos][sum];
	d[pos][sum] = 0;
	if(sum+a[pos+1] <= 20)
		d[pos][sum] += go(pos+1,sum+a[pos+1]);
	if(0 <= sum-a[pos+1])
		d[pos][sum] += go(pos+1,sum-a[pos+1]);
	return d[pos][sum];
}
int main(){
	memset(d,-1,sizeof(d));
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	cout << go(1,a[1]);
}
