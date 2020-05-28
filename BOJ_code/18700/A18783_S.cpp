// BOJ 18783 Swapity Swapity Swap
// Sparse table

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m, k; cin >> n >> m >> k;

	vector<pii> swap(m);
	for (int i = 0; i < m; ++i) cin >> swap[i].first >> swap[i].second;

	vector<vector<int>> par(n + 1, vector<int>(30));
	for (int i = 1; i <= n; ++i) {
		int t = i;
		for (auto lr : swap) {
			if (!(lr.first <= t && t <= lr.second)) continue;
			t = lr.second - (t - lr.first);
		}
		par[t][0] = i;
	}

	for (int j = 1; j < 30; ++j)
		for (int i = 1; i <= n; ++i)
			par[i][j] = par[par[i][j - 1]][j - 1];

	vector<int> ans(n + 1);
	for (int i = 1; i <= n; ++i) {
		int c = k, x = 0, res = i;
		while (c) {
			if (c % 2) res = par[res][x];
			c /= 2;
			x++;
		}
		ans[i] = res;
	}

	for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
}