// BOJ 13346 Hamming Ellipses
// dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;

ll dp[101][10][201];
vector<int> f1, f2;
ll go(int i, int k, int d, int q) {
	ll& res = dp[i][k][d];
	if (res != -1) return res;
	if (i == 1) {
		if (!d) return res = 1;
		else return res = 0;
	}
	if (d < 0) return res = 0;
	res = 0;
	for (int j = 0; j < q; ++j) {
		if (f1[i - 1] == j && f2[i - 1] == j) res += go(i - 1, j, d, q);
		else if (f1[i - 1] == j || f2[i - 1] == j) res += go(i - 1, j, d - 1, q);
		else res += go(i - 1, j, d - 2, q);
	}
	return res;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int q, n, d; cin >> q >> n >> d;

	memset(dp, -1, sizeof dp);
	f1 = vector<int>(n + 1);
	f2 = vector<int>(n + 1);
	for (int i = 1; i <= n; ++i) {
		char c; cin >> c; f1[i] = c - '0';
	}
	for (int i = 1; i <= n; ++i) {
		char c; cin >> c; f2[i] = c - '0';
	}

	ll ans = 0;
	for (int i = 0; i < q; ++i) {
		if (f1[n] == i && f2[n] == i) ans += go(n, i, d, q);
		else if (f1[n] == i || f2[n] == i) ans += go(n, i, d - 1, q);
		else ans += go(n, i, d - 2, q);
	}
	cout << ans;
}