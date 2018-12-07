#include<bits/stdc++.h>
using namespace std;
int gcd(int k, int l){
	return l ? gcd(l, k%l) : k;
}
int lcm(int k, int l){
	return k / gcd(k,l) * l;
}
int main(){
	int a,b; cin >>a>>b;
	cout << gcd(a,b)<<"\n"<<lcm(a,b);
}
