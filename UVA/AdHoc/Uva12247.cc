#include<bits/stdc++.h>
using namespace std;
int main(){
    while(true){
        int a,b,c,x,y;
        cin >>a>>b>>c>>x>>y;
        if(!a && !b && !c && !x && !y) break;
        set<int> cards;
        cards.insert(a);
        cards.insert(b);
        cards.insert(c);
        cards.insert(x);
        cards.insert(y);
        
        bool flag = false;
        int ans = 0;
        // 범위가 작으므로 완전탐색한다.
        for(int card = 1; card <= 52; card++){
            
            if(cards.count(card)) continue;
            
            set<int> princess;    
            princess.insert(a);
            princess.insert(b);
            princess.insert(c);
            
            int princesswin = 0;
            vector<int> prince = {card,x,y};
            sort(prince.begin(), prince.end());
            
            // 공주에게 가장 유리한 조건은 왕자의 모든 카드에 대해서 자신이 낼 수 있는 가장 작은 값을 내는 것이다.
            // 한 card 루프문 당 완전탐색을 한다고 할 때 왕자가 지는 케이스가 없어야한다.
            // 완전탐색으로도 풀 수 있지만, 공주가 2번만 이기는 경우가 있으면 왕자는 질수도 이길수도 있기 때문에 탐욕적으로 풀 수 있다.
            for(int i=0; i<prince.size(); i++){
                set<int>::iterator it = princess.upper_bound(prince[i]);
                if(it == princess.end())
                    princesswin++;
                else
                    princess.erase(it);
            }
            if(princesswin >= 2){
                flag = true;
                ans = card;
                break;
            }
        }
        
        if(flag) cout << ans << "\n";
        else cout << -1 <<"\n";
    }
}
