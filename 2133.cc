#include<bits/stdc++.h>
using namespace std;
int d[30];
int main(){
	int n; cin >> n;
	if(n%2 == 1){
		cout << 0; return 0;
	}
	d[2] = 3;
	for(int i=4; i<=n; i+=2){
		d[i] = d[2]*d[i-2]+2;
		for(int j=2; j<=i-4; j+=2)
			d[i] += 2*d[j];
	}
	cout << d[n];
}
