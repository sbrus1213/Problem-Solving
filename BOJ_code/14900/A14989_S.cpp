// BOJ 14989 Booming Business
// dynamic programming

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int h, w;
ll combi[601][601];
ll dp[301][301][301];
void init() {
	combi[0][0] = 1;
	for (int i = 1; i <= 600; ++i) {
		combi[i][0] = combi[i][i] = 1;
		for (int j = 1; j < i; ++j)
			combi[i][j] = (combi[i - 1][j] + combi[i - 1][j - 1]) % mod;
	}
}
ll ncm(int n, int m) {
	return combi[n][m];
}
ll nhm(int n, int m) {
	return ncm(n + m - 1, m);
}
ll go(int hgt, int prv, int rem) {
	if (dp[hgt][prv][rem] != -1) return dp[hgt][prv][rem];
	if (hgt == h) return dp[hgt][prv][rem] = nhm(prv, rem);

	ll& ret = dp[hgt][prv][rem];
	ret = 0;
	for (int i = 1; i <= rem - h + hgt; ++i)
		ret = (ret + (go(hgt + 1, i, rem - i) * nhm(prv, i)) % mod) % mod;
	return ret;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	init();

	cin >> h >> w;

	memset(dp, -1, sizeof dp);
	if (h == 1) cout << (w == 1);
	else if (h > w) cout << 0;
	else if (h == w) cout << 1;
	else cout << go(2, 1, w - 1);
}