#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin >> tc;
    cin.ignore();
    for(int t=1; t<=tc; t++){
        string s;
        getline(cin, s);
        istringstream iss(s);
        string card;
        
        // pile은 bottom이 back이 된다.
        deque<string> pile, hands;
        while(getline(iss, card,' ')){
            pile.push_back(card);
        }
        
        // pile의 back에서 25개를 hand의 back으로 가져옴
        for(int i=1; i<=25; i++){
            hands.push_front(pile.back());
            pile.pop_back();
        }
        
        int X=0, Y=0;
        for(int loop=1; loop <= 3; loop++){
            string top = pile.back();
            int rank = (int)(top[0]-'0');
            if(2 <= rank && rank <= 9){
                X = rank;
                Y += X;
            }else
                X = 10, Y += X;
            
            // 맨 위와 10-X를 pile의 back에서 제거
            pile.pop_back();
            for(int i=1; i<=10-X; i++)
                pile.pop_back();
        }
        if(Y < pile.size()){
            // 답은 pile 안에 있다.
            for(int i=1; i<Y; i++){
                pile.pop_front();
            }
            printf("Case %d: %s\n", t, pile.front().c_str());
        }else if(Y > pile.size()){
            // 답은 hand에 있으다.
            Y = Y - pile.size();
            for(int i=1; i<Y; i++)
                hands.pop_front();
            printf("Case %d: %s\n", t, hands.front().c_str());
        }else{
            printf("Case %d: %s\n", t, pile.back().c_str());
        }
    }
    
}
