
#include<bits/stdc++.h>
using namespace std;
int p[2001][2001];
int a[2001];
int isPal(int s, int e){
	if(s == e) return p[s][e] = 1;
	if(s+1 == e) return p[s][e] = (a[s] == a[e] ? 1 : 0);
	if(p[s][e] != -1) return p[s][e];
	return p[s][e] = isPal(s+1,e-1) * (a[s] == a[e] ? 1 : 0);	
}
int main(){
	int n; cin >> n;
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);
	memset(p,-1,sizeof(p));
	for(int i=1; i<=n; i++)
		for(int j=i; j<=n; j++)
			p[i][j] = isPal(i,j);
	int k; cin >> k;
	for(int i=0; i<k; i++){
		int s,e; scanf("%d%d", &s, &e);
		printf("%d\n", p[s][e]);
	}
}
