#include<bits/stdc++.h>
using namespace std;
int d[501][501];
int a[501], s[501];
int sum(int start, int end){
	return s[end] - s[start-1];
}
int go(int start, int end){
	if(start == end) return 0;
	if(d[start][end]) return d[start][end];
	d[start][end] = INT32_MAX;
	for(int i=start; i<end; i++){
		d[start][end] = min(d[start][end], go(start,i) + go(i+1,end) + sum(start,i) + sum(i+1,end));
	}
	return d[start][end];
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		for(int i=1; i<=n; i++)
			scanf("%d", &a[i]);
		s[1] = a[1];
		for(int i=2; i<=n; i++) s[i] = s[i-1] + a[i];
		cout << go(1,n) << endl;
	}
}
