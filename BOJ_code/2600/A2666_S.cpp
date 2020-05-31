// BOJ 2666 벽장문의 이동
// dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1e6;

vector<int> pos;
int dp[21][21][21], n;

int go(int i, int l, int r) {
	if (dp[i][l][r] != inf) return dp[i][l][r];

	int& ret = dp[i][l][r];
	if (pos[i] < l) {
		ret = min(ret, go(i - 1, pos[i], r) + (l - pos[i]));
		if (pos[i] != 1)
			ret = min(ret, go(i - 1, pos[i] - 1, pos[i]) + (l + r + 1 - 2 * pos[i]));
	}
	else if (pos[i] == l) {
		ret = min(ret, go(i - 1, l, r));
		if (l != 1)
			ret = min(ret, go(i - 1, l - 1, l) + (1 + r - l));
	}
	else if (l < pos[i] && pos[i] < r) {
		ret = min(ret, go(i - 1, pos[i], r) + (pos[i] - l));
		ret = min(ret, go(i - 1, l, pos[i]) + (r - pos[i]));
	}
	else if (pos[i] == r) {
		if (r != n)
			ret = min(ret, go(i - 1, r, r + 1) + (r - l + 1));
		ret = min(ret, go(i - 1, l, r));
	}
	else if (r < pos[i]) {
		if (pos[i] != n)
			ret = min(ret, go(i - 1, pos[i], pos[i] + 1) + (2 * pos[i] - l - r + 1));
		ret = min(ret, go(i - 1, l, pos[i]) + (pos[i] - r));
	}
	return ret;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int sl, sr; cin >> n >> sl >> sr;

	int q; cin >> q;
	pos = vector<int>(q + 1);
	for (int i = q; i >= 1; --i)
		cin >> pos[i];

	for (int i = 1; i <= q; ++i)
		for (int l = 1; l <= n; ++l)
			for (int r = 1; r <= n; ++r)
				dp[i][l][r] = inf;

	cout << go(q, sl, sr);
}