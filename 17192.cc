#include<bits/stdc++.h>
using namespace std;
int a[404], d[404][404];
int main(){
    int n, k, maximum = 0, total = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maximum = max(a[i], maximum);
        d[i][0] = maximum * i;
        for (int j = 1; j <= k; j++){
            d[i][j] = 987654321;
            int local = a[i];
            for (int z = i - 1; z >= 0; z--){
                d[i][j] = min(d[i][j], d[z][j - 1] + (i - z) * local);
                local = max(local, a[z]);
            }
        }
        total += a[i];
    }
    cout << d[n][k] - total;
}
