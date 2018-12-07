#include<bits/stdc++.h>
using namespace std;
int n, a[1001], d[1001];
int go(int left){
    if(left == 0) return 0;
    if(d[left]) return d[left];
    for(int i=1; i<=left; i++){
        d[left] = max(d[left], go(left-i)+a[i]);
    }
    return d[left];
}
int main(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    cout << go(n);
}
