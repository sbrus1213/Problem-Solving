// BOJ 11089 Circuit Counting
// dynamic programming - knapsack

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int lim;

inline int pi(pii p) {
	return (lim - p.second) * (2 * lim + 1) + p.first + lim;
}
inline pii ip(int i) {
	return pii(i % (2 * lim + 1) - lim, lim - i / (2 * lim + 1));
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;
	lim = n * 10;

	vector<pii> vec(n);
	for (int i = 0; i < n; ++i) cin >> vec[i].first >> vec[i].second;

	int sz = (2 * lim + 1) * (2 * lim + 1);
	vector<vector<ll>> dp(2, vector<ll>(sz));
	dp[1][pi(pii(0, 0))] = 1;
	for (int i = 0; i < n; ++i) {
		int a = i % 2, b = (i + 1) % 2;
		for (int j = 0; j < sz; ++j) dp[a][j] = dp[b][j];
		for (int j = 0; j < sz; ++j) {
			pii cur = ip(j);
			pii nxt = pii(cur.first + vec[i].first, cur.second + vec[i].second);
			if (nxt.first < -lim || nxt.first > lim) continue;
			if (nxt.second < -lim || nxt.second > lim) continue;
			dp[a][pi(nxt)] += dp[b][j];
		}
	}
	cout << dp[(n + 1) % 2][pi(pii(0, 0))] - 1;
}