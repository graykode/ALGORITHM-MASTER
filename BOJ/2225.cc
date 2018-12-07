#include<bits/stdc++.h>
#define mod 1000000000
using namespace std;
int d[201][201];
int go(int chunk, int p){
	if(chunk == 1) return 1;
	if(d[p][chunk]) return d[p][chunk];
	for(int i=0; i<=p; i++)
		d[p][chunk] = (d[p][chunk]%mod + go(chunk-1, p-i)%mod)%mod;
	return d[p][chunk]%mod;
}
int main(){
	int n,k; cin >> n>> k;
	cout << go(k,n)%mod;
}
