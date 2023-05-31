#include <bits/stdc++.h>

using namespace std;

int used[101][101];

int main() {
	string s;
	vector<pair<int, int>> b, I, u;
	vector<string> str;
	while (getline(cin, s, '\n')) {
		str.push_back(s);
	}

	for (auto row = 0; row < str.size(); row++) {
		int n = str[row].size();
		s = str[row];
		for (int i = 0; i < n; i++) {
			if (i+2 < n && (s.substr(i, 3) == "[b]" || s.substr(i, 3) == "[B]")) {
				b.push_back({row, i});
			} else if (i+2 < n && (s.substr(i, 3) == "[i]" || s.substr(i, 3) == "[I]")) {
				I.push_back({row, i});
			} else if (i+2 < n && (s.substr(i, 3) == "[u]" || s.substr(i, 3) == "[U]")) {
				u.push_back({row, i});
			} else if (i+3 < n && (s.substr(i, 4) == "[/b]" || s.substr(i, 4) == "[/B]")) {
				if (!b.empty()) {
					used[row][i] = 1;
					used[b.back().first][b.back().second] = 1;
					b.pop_back();
				}
			} else if (i+3 < n && (s.substr(i, 4) == "[/i]" || s.substr(i, 4) == "[/I]")) {
				if (!I.empty()) {
					used[row][i] = 1;
					used[I.back().first][I.back().second] = 1;
					I.pop_back();
				}
			} else if (i+3 < n && (s.substr(i, 4) == "[/u]" || s.substr(i, 4) == "[/U]")) {
				if (!u.empty()) {
					used[row][i] = 1;
					used[u.back().first][u.back().second] = 1;
					u.pop_back();
				}
			}
		}
	}
	for (int row = 0; row < str.size(); row++) {
		for (int i = 0; i < str[row].size(); i++) {
			if (used[row][i] == 1) {
				str[row][i] = '<';
				if (str[row][i+1] == '/') {
					if (str[row][i+2] >= 'A' && str[row][i+2] <= 'Z') str[row][i+2] = str[row][i+2]-'A'+'a';
					str[row][i+3] = '>';
				} else {
					if (str[row][i+1] >= 'A' && str[row][i+1] <= 'Z') str[row][i+1] = str[row][i+1]-'A'+'a';
					str[row][i+2] = '>';
				}
			}
		}
	}
	int f = 0;
	for (auto s : str) {
		if (f) cout << "\n";
		cout << s;
		f = 1;
	}
	return 0;
}
