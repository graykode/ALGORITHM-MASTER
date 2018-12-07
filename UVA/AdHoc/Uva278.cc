#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        char piece; cin >> piece;
        int m,n; cin >> m >> n;
        if(piece == 'Q'){
            cout << min(m,n) <<"\n";
        }else if(piece == 'K'){
            cout << ((m+1)/2) * ((n+1)/2) <<"\n";
        }else if(piece == 'r'){
            cout << min(m,n) <<"\n";
        }else if(piece == 'k'){
            cout << ((m+1)/2) * ((n+1)/2) + (m/2) * (n/2) <<"\n";
        }
    }
}
