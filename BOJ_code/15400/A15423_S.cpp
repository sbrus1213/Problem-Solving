// BOJ 15423 Canonical Coin Systems
// dynamic programing

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> coin(n);
	for (int i = 0; i < n; ++i) cin >> coin[i];
	sort(coin.begin(), coin.end());

	int mx = coin.back() * 2;
	vector<int> dp(mx + 1, mx * 2);
	dp[0] = 0;
	for (int i = 1; i <= mx; ++i) {
		for (int j = 0; j < n; ++j) {
			if (coin[j] > i) break;
			dp[i] = min(dp[i], dp[i - coin[j]] + 1);
		}
	}

	for (int i = 2; i <= mx; ++i) {
		int money = i, cnt = 0;
		for (int j = n - 1; j >= 0 && money; --j) {
			if (money < coin[j]) continue;
			cnt += money / coin[j];
			money %= coin[j];
		}
		if (cnt != dp[i]) {
			cout << "non-canonical";
			return 0;
		}
	}
	cout << "canonical";
}