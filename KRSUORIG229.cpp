#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<tuple<char, int, int>> v;
	int me = -1, sz = 0;
	for (; n--; ) {
			int x;
			char c, alpha;
			cin >> x >> c;
			if (c == 'I') {
				cin >> alpha;
				if (me == -1) {
					v.push_back({alpha, 1, x});
					me = x;
				} else {
					for (int i = 0; i < v.size(); i++) {
						if (me == get<1>(v[i])) {
							for (int i = 0; i < v.size(); i++) {
								if (me <= get<1>(v[i])) {
									get<1>(v[i]) += x;
									get<2>(v[i]) += x;
								}
							}
							v.push_back({alpha, me, me + x - 1});
							me = me + x - 1;
							break;
						} else if (get<1>(v[i]) < me && me <= get<2>(v[i])) {
							auto E = v[i];
							v.erase(v.begin() + i);
							for (int i = 0; i < v.size(); i++) {
								if (me < get<1>(v[i])) {
									get<1>(v[i]) += x;
									get<2>(v[i]) += x;
								}
							}
							v.push_back({alpha, me, me + x - 1});
							v.push_back({get<0>(E), get<1>(E), me - 1});
							v.push_back({get<0>(E), me + x, get<2>(E) + x});
							me = me + x - 1;
							break;
						}
					}
				}
				sz += x;
			} else if (c == 'H') {
				if (me == -1);
				else {
					me -= x;
					if (me < 1) me = 1;
				}
			} else if (c == 'L') {
				if (me == -1);
				else {
					me += x;
					if (me > sz) me = sz;
				}
			}
	}

  int f = 0;
	for (; m--; ) {
		int x; cin >> x;
		for (int i = 0; i < v.size(); i++) {
			if (get<1>(v[i]) <= x && x <= get<2>(v[i])) {
				if (f) cout << "\n";
				cout << get<0>(v[i]);
				f = 1;
				break;
			}
		}
	}

	return 0;
}
