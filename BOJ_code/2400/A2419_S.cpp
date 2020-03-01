// BOJ 2419 »ç¼ö¾ÆÅÁ
// Dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1e9;
#define BtoE(vec) vec.begin(), vec.end()

int n, m, s;
vector<int> x;
int dp[301][301];

int solve(int i, int j, int rem) {
	if (!rem) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	int l = min(i, j), r = max(i, j);

	dp[i][j] = INF;

	if (r != n) dp[i][j] = min(dp[i][j], solve(l, r + 1, rem - 1) + rem * (x[r + 1] - x[j]));
	if (l != 0) dp[i][j] = min(dp[i][j], solve(r, l - 1, rem - 1) + rem * (x[j] - x[l - 1]));

	return dp[i][j];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	x.resize(n);
	for (int i = 0; i < n; ++i) cin >> x[i];
	x.push_back(0);
	sort(BtoE(x));

	for (int i = 0; i <= n; ++i) if (!x[i]) { s = i; break; }

	int res = -1;
	for (int i = 0; i <= n; ++i) {
		memset(dp, -1, sizeof(dp));
		res = max(res, i * m - solve(s, s, i));
	}
	cout << res;
}