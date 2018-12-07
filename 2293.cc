#include<bits/stdc++.h>
using namespace std;
int a[301], d[10001];
int main(){
	int n,k; cin >>n>>k;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=a[i]; i<=n; i++){
		for(int j=a[i]; j<=k; j++){
			if(j == a[i]) d[j]++;
			else if(j > a[i]) d[j] += d[j-a[i]];
		}
	}
	cout << d[k];
}
