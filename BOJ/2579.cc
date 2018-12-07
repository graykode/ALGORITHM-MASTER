#include<bits/stdc++.h>
using namespace std;
int a[301], n, d[301][3];
int go(int p, int s){
	if(p == 0) return 0;
	if(d[p][s]) return d[p][s];
	if(s == 2) d[p][s] = go(p-1,0);
	else {
		d[p][s] = go(p-1,s+1)+a[p];
		if(p-2 >= 0) d[p][s] = max(d[p][s], go(p-2,0)+a[p]);
	}
	return d[p][s];
}
int main(){
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	cout << go(n,0);
}
 
