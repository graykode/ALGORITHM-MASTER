#include<bits/stdc++.h>
using namespace std;
// 4개의 배열은 'S'(스페이스), 'H'(하트), 'D'(다이아몬드), 'C'(클로버) 순
bool isTrump[4]; // 각 모양이 no-trump을 만족하는지
bool isAce[4], isQueen[4], isKing[4], isJack[4];
int cnt[4], point, extrapoint;	 // 각 모양의 갯수
char suits[4] = {'S', 'H', 'D', 'C'};
void setRank(int index, char rank) {
	// 카드 숫자에 따라서
	switch (rank) {
	case 'A':
		point += 4;
		isAce[index] = true;
		break;
	case 'J':
		point += 1;
		isJack[index] = true;
		break;
	case 'Q':
		point += 2;
		isQueen[index] = true;
		break;
	case 'K':
		point += 3;
		isKing[index] = true;
		break;
	}
}
int main() {
	string s;
	while (getline(cin, s)) {
		// 초기화
		point = extrapoint =  0;
		memset(cnt, 0, sizeof(cnt));
		memset(isTrump, false, sizeof(isTrump));
		memset(isAce, false, sizeof(isAce));
		memset(isQueen, false, sizeof(isQueen));
		memset(isKing, false, sizeof(isKing));
		memset(isJack, false, sizeof(isJack));

		istringstream iss(s);
		string card;
		// istringstream을 사용하여 빈칸단위로 split할 때는 다음과 같이 사용한다.
		while (getline(iss, card, ' ')) {
			
			// 각 모양에 따라서
			char suit = card[1];
			char rank = card[0];
			switch (suit){
			case 'S':
				cnt[0]++;
				setRank(0, rank);
				break;
			case 'H':
				cnt[1]++;
				setRank(1, rank);
				break;
			case 'D':
				cnt[2]++;
				setRank(2, rank);
				break;
			case 'C':
				cnt[3]++;
				setRank(3, rank);
				break;
			}
		}

		for (int i = 0; i < 4; i++) {
			if (isAce[i]) isTrump[i] = true;

			if (isKing[i] && cnt[i] <= 1) point--;
			else if (isKing[i] && cnt[i] > 1) isTrump[i] = true;

			if (isQueen[i] && cnt[i] <= 2) point--;
			else if (isQueen[i] && cnt[i] > 2) isTrump[i] = true;

			if (isJack[i] && cnt[i] <= 3) point--;

			if (cnt[i] == 2) extrapoint++;
			else if (cnt[i] < 2) extrapoint+=2;
		}
		if (isTrump[0] && isTrump[1] && isTrump[2] && isTrump[3] && point >= 16)
			printf("BID NO-TRUMP\n");
		else if (point + extrapoint >= 14) {
			int ans = 0, Max = -1;
			for (int i = 0; i < 4; i++) {
				if (cnt[i] > Max) {
					Max = cnt[i];
					ans = i;
				}
			}
			printf("BID %c\n", suits[ans]);
		}
		else printf("PASS\n");
	}
}
