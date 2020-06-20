// BOJ 5904 Moo 게임
// dynamic programming

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	ll n; cin >> n;

	vector<ll> dp = { 0 };
	for (int i = 3;; ++i) {
		ll x = dp.back();
		dp.push_back(2 * x + i);
		if (dp.back() >= n) break;
	}

	for (int i = dp.size() - 1; i >= 0; --i) {
		if (dp[i] > n) continue;
		if (dp[i] + (i + 3) < n) {
			n -= dp[i] + (i + 3);
		}
		else if (dp[i] < n) {
			if (dp[i] + 1 == n) cout << 'm';
			else cout << 'o';
			return 0;
		}
	}
}