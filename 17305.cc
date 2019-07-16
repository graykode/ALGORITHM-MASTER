#include <bits/stdc++.h>
using namespace std;
vector<long long> threes, fives;
int main()
{
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++){
        int mod, value;
        cin >> mod >> value;
        if(mod == 3)
            threes.push_back(value);
        else if (mod == 5)
            fives.push_back(value);
    }
    sort(threes.begin(), threes.end());
    reverse(threes.begin(), threes.end());
    sort(fives.begin(), fives.end());
    reverse(fives.begin(), fives.end());

    vector<long long> sum_three(threes.size(), 0);
    vector<long long> sum_five(fives.size(), 0);

    if(threes.size() > 0){
        sum_three[0] = threes[0];
        for (int i = 1; i < threes.size(); i++)
            sum_three[i] = sum_three[i - 1] + threes[i];
    }
    if(fives.size() > 0){
        sum_five[0] = fives[0];
        for (int i = 1; i < fives.size(); i++)
            sum_five[i] = sum_five[i - 1] + fives[i];
    }

    int max_three = w / 3;
    int max_five = w / 5;
    long long ans = 0;
    for (int i = 0; i <= max_five; i++){
        int three = min((w - i * 5) / 3, (int)sum_three.size());
        int five = min(i, (int)sum_five.size());
        if(three == 0 && five == 0)
            ans = max(ans, (long long)0);
        else if (five == 0)
            ans = max(ans, sum_three[three - 1]);
        else if(three == 0)
            ans = max(ans, sum_five[five - 1]);
        else{
            ans = max(ans, sum_three[three - 1] + sum_five[five - 1]);
        }
    }
    cout << ans;
}
