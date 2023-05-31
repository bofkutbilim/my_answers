#include <bits/stdc++.h>

using namespace std;

int used[8];

void permutation(string & s, string &ans) {
	if (ans.size() == s.size()) {
		cout << ans << "\n";
	} else {
		for (int i = 0; i < s.size(); i++) {
			if (used[i] == 0) {
				ans += s[i];
				used[i] = 1;
				permutation(s, ans);
				used[i] = 0;
				ans.pop_back();
			}
		}
	}
}

int main() {
	string s, ans = "";
	cin >> s;
	sort(s.begin(), s.end());
	permutation(s, ans);
	return 0;
}
