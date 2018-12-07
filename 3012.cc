#include<bits/stdc++.h>
#define mod 100000
using namespace std;
string a;
string open = "([{";
string close = ")]}";
long long d[201][201];
bool overflow = false;
int n;
long long go(int s, int e){
	if(s == e) return 0;
	if(s > e) return 1;
	if(d[s][e] != -1) return d[s][e];
	d[s][e] = 0;
	for(int k=s+1; k<=e; k+=2){
		for (int l=0; l<3; l++) {
           		if ((a[s] == open[l] || a[s] == '?') && (a[k] == close[l] || a[k] == '?')) {
               			long long temp = go(s+1,k-1) * go(k+1,e);
				if(d[s][e] + temp > mod){
					overflow = true;
				}
				d[s][e] += temp;
				d[s][e] %= mod;
			}
		}
	}
	return d[s][e];
}
int main(){
	memset(d,-1,sizeof(d));
	cin >> n >> a;
	long long ans =  go(0,n-1);
	if (overflow) {
		if(ans == 0) printf("0");
		else printf("%05lld",ans);
	}
	else printf("%lld",ans);
}
