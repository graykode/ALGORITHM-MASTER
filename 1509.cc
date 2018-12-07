#include<bits/stdc++.h>
using namespace std;
int p[2501][2501];
int d[2501];
string str;
int isPal(int s,int e){
	if(s == e) return 1;
	if(s+1 == e) return str[s] == str[e] ? 1 : 0;
	if(p[s][e] != -1) return p[s][e];
	return p[s][e] = isPal(s+1,e-1) * (str[s] == str[e] ? 1 : 0);
}
int go(int end){
	if(end == -1) return 0;
	if(d[end]) return d[end];
	d[end] = 30000;
	for(int i=end; i>=0; i--){
		if(p[i][end] == 1){
			d[end] = min(go(i-1)+1, d[end]);
		}
	}
	return d[end];
}
int main(){
	memset(p,-1,sizeof(p));
	cin >> str;
	for(int i=0; i<str.length(); i++)
		for(int j=i; j<str.length(); j++)
			p[i][j] = isPal(i,j);
	cout << go(str.length()-1);
}
