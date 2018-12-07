#include<bits/stdc++.h>
using namespace std;
int d[1001], a[1001], n;
int go(int pos){
	if(d[pos]) return d[pos];
	for(int i=pos+1; i<=n; i++){
		if(a[pos] < a[i])
			d[pos]= max(d[pos], go(i)+a[i]);
	}
	return d[pos];
}
int main(){
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	cout << go(0);
}
