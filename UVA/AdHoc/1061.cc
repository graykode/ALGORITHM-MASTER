#include<bits/stdc++.h>
using namespace std;
map<string, vector<string>> m;
map<string, string> shortcut;
struct person {
	string blood, rh;
};
string child(person par1, person par2) {
	vector<string> ans;
	map<string, bool> is;
	for (int i = 0; i < m[par1.blood].size(); i++) {
		for (int j = 0; j < m[par2.blood].size(); j++) {
			for (int x = 0; x < m[par1.blood][i].length(); x++) {
				for (int y = 0; y < m[par2.blood][j].size(); y++) {
					char first = m[par1.blood][i][x];
					char second = m[par2.blood][j][y];
					char arr[2] = { first, second };
					sort(arr, arr+2);
					
					string s = "";
					s += arr[0];
					s += arr[1];
					if (!is[shortcut[s]]) {
						is[shortcut[s]] = true;
						if (par1.rh == "-" && par2.rh == "-")
							ans.push_back(shortcut[s] + "-");
						else {
							ans.push_back(shortcut[s] + "-");
							ans.push_back(shortcut[s] + "+");
						}
					}
				}
			}
		}
	}
	if (ans.size() == 0) return "IMPOSSIBLE";
	else if (ans.size() == 1) return ans[0];
	else {
		string s = "{";
		for (int i = 0; i < ans.size(); i++)
			s += ans[i] + ", ";
		s = s.substr(0, s.length() - 2) + "}";
		return s;
	}
}
string parent(person par, person chi) {
	vector<string> ans;
	map<string, bool> is;
	vector<string> all = {"AA", "AO", "BB", "BO", "AB", "OO"};
	for (int i = 0; i < m[par.blood].size(); i++) {
		for (int j = 0; j < all.size(); j++) {
			for (int x = 0; x < m[par.blood][i].length(); x++) {
				for (int y = 0; y < all[j].size(); y++) {
					char first = m[par.blood][i][x];
					char second = all[j][y];
					char arr[2] = { first, second };
					sort(arr, arr + 2);

					string s = "";
					s += arr[0];
					s += arr[1];

					for (int z = 0; z < m[chi.blood].size(); z++) {
						if (s == m[chi.blood][z] && !is[shortcut[all[j]]]) {
							is[shortcut[all[j]]] = true;
							if (par.rh == "-" && chi.rh == "+")
								ans.push_back(shortcut[all[j]] + "+");
							else {
								ans.push_back(shortcut[all[j]] + "+");
								ans.push_back(shortcut[all[j]] + "-");
							}
						}
					}
				}
			}
		}
	}
	if (ans.size() == 0) return "IMPOSSIBLE";
	else if (ans.size() == 1) return ans[0];
	else {
		string s = "{";
		for (int i = 0; i < ans.size(); i++)
			s += ans[i] + ", ";
		s = s.substr(0, s.length() - 2) + "}";
		return s;
	}
}
int main() {
	m["A"].push_back("AA");
	m["A"].push_back("AO");
	m["AB"].push_back("AB");
	m["B"].push_back("BB");
	m["B"].push_back("BO");
	m["O"].push_back("OO");

	shortcut["AA"] = "A";
	shortcut["AO"] = "A";
	shortcut["BB"] = "B";
	shortcut["BO"] = "B";
	shortcut["AB"] = "AB";
	shortcut["OO"] = "O";
	int tc = 0;
	while (true) {
		string par1, par2, chi;
		cin >> par1 >> par2 >> chi;
		if (par1 == "E" && par2 == "N" && chi == "D") break;
		if (chi == "?") {
			person p1{ par1.substr(0,par1.length() - 1) , par1.substr(par1.length() - 1) };
			person p2{ par2.substr(0,par2.length() - 1) , par2.substr(par2.length() - 1) };
			printf("Case %d: %s %s %s\n", ++tc, par1.c_str(), par2.c_str(), child(p1, p2).c_str());
		}
		else if (par1 == "?") {
			person p{ par2.substr(0,par2.length() - 1) , par2.substr(par2.length() - 1) };
			person c{ chi.substr(0,chi.length() - 1) , chi.substr(chi.length() - 1) };
			printf("Case %d: %s %s %s\n", ++tc, parent(p, c).c_str(), par2.c_str(), chi.c_str());
		}
		else if (par2 == "?") {
			person p{ par1.substr(0,par1.length() - 1) , par1.substr(par1.length() - 1) };
			person c{ chi.substr(0,chi.length() - 1) , chi.substr(chi.length() - 1) };
			printf("Case %d: %s %s %s\n", ++tc, par1.c_str(), parent(p, c).c_str(), chi.c_str());
		}
	}
}
