#include<bits/stdc++.h>
using namespace std;
int a[101], t[101], one[101], s[101], d[101][101];
int n,m;
int sum(int start, int end){
	return s[end] - s[start-1];
}
int go(int pos, int mass){
	if(mass == 1) return one[pos];
	if(d[pos][mass] != -9999999) return d[pos][mass];
	d[pos][mass] = -9999999;
	int x = pos%2 == 0 ? pos/2 : pos/2+1;
	if(mass <= x){
		d[pos][mass] = max(d[pos][mass],go(pos-1,mass));
		for(int i=pos-2; i>=1; i--){
			d[pos][mass] = max(d[pos][mass], go(i,mass-1) + sum(i+2,pos));
		}
	}
	return d[pos][mass];
}
int main(){
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) d[i][j] = -9999999;
	for(int i=1; i<=n; i++) cin >> a[i];
	int high = one[1] = s[1] = t[1] = a[1];
	for(int i=2; i<=n; i++){
		t[i] = t[i-1] + a[i];
		s[i] = s[i-1] + a[i];
		if(a[i-1] < a[i])
			t[i] = max(t[i], a[i]);
		one[i] = high = max(high, t[i]);
	}
	cout << go(n,m);
}
