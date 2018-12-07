#include<bits/stdc++.h>
using namespace std;
struct Person {
	set<int> problem;
	int time;
	int temp[101];
};
struct Team {
	int number, problem, score;
};
map<int, Person> m;
vector<Team> a;
bool cmp(const Team& x, const Team& y) {
	if (x.problem > y.problem) return true;
	else if (x.problem == y.problem) {
		if (x.score < y.score) return true;
		else if (x.score == y.score)
			return x.number < y.number;
	}
	return false;
}
int main() {
	int t;
	stringstream ss;
	string row; getline(cin, row);
	//ss.clear();
	ss << row;
	ss >> t;
	getline(cin, row);
	ss.clear();
	while (t--) {
		m.clear();
		a.clear();
		while (getline(cin, row)) {
			if (row.empty()) break;
			int perNum, proNum, time;
			char state;
			ss.clear();
			ss << row;
			ss >> perNum >> proNum >> time >> state;
			set<int> s = m[perNum].problem;
			if (state == 'I') {
				m[perNum].temp[proNum] += 20;
			}
			else if (state == 'C') {
				if (s.find(proNum) == s.end()) {
					s.insert(proNum);
					m[perNum].time += m[perNum].temp[proNum] + time;
				}
			}
			m[perNum].problem = s;
		}
		for (map<int, Person>::iterator iter = m.begin(); iter != m.end(); iter++) {
			int number = iter->first;
			int problem = iter->second.problem.size();
			int score = iter->second.time;
			a.push_back({number, problem, score});
		}
		sort(a.begin(), a.end(), cmp);
		for (int i = 0; i < a.size(); i++) {
			cout << a[i].number << " " << a[i].problem << " " << a[i].score << endl;
		}
		if (t) cout << endl;
	}
	return 0;
}
