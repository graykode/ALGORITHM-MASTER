#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b,c,d;
	cin >>a>>b>>c>>d;
	long x = strtol((a+b).c_str(), NULL, 10);
	long y = strtol((c+d).c_str(), NULL, 10);
	cout <<x+y;
}
