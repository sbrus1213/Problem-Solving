// BOJ 13350 Presidential Elections
// dynamic programming - knapsack

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1e9 + 7;

struct state {
	int d, c, f, u;
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	int tot = 0, cer = 0;
	vector<state> nation;
	for (int i = 0; i < n; ++i) {
		state s;
		cin >> s.d >> s.c >> s.f >> s.u;
		tot += s.d;
		if (s.c > s.f + s.u) cer += s.d;
		else if (s.f >= s.c + s.u) cer -= s.d;
		else nation.push_back(s);
	}

	vector<int> cnt(2 * tot + 1, inf), tmp(2 * tot + 1);
	cnt[tot + cer] = 0;
	for (const auto& s : nation) {
		int win = (s.f + s.u - s.c) / 2 + 1;
		for (int j = 0; j <= 2 * tot; ++j)
			if (j < s.d) tmp[j] = cnt[j + s.d];
			else if (j > 2 * tot - s.d) tmp[j] = cnt[j - s.d] + win;
			else tmp[j] = min(cnt[j + s.d], cnt[j - s.d] + win);
		for (int j = 0; j <= 2 * tot; ++j) cnt[j] = min(tmp[j], inf);
	}

	int ans = inf;
	for (int i = tot + 1; i <= 2 * tot; ++i) ans = min(ans, cnt[i]);

	if (ans == inf) cout << "impossible";
	else cout << ans;
}