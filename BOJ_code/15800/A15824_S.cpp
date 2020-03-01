// BOJ 15824 ≥  ∫Ωø°¥¬ ƒ∏ªÁ¿ÃΩ≈¿Ã ∏¿¿÷¥‹¥Ÿ
// dynamic programming & exponentiation by squaring

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define BtoE(vec) vec.begin(), vec.end()
const int mod = 1000000007;

ll exp2(int times) {
	ll res = 1, x = 2;

	while (times) {
		if (times % 2)
			res = (res * x) % mod;
		times >>= 1;
		x = (x * x) % mod;
	}
	return res;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	vector<ll> scobil, dp;

	cin >> n;
	scobil.resize(n);
	dp.resize(n);

	for (int i = 0; i < n; ++i) cin >> scobil[i];
	sort(BtoE(scobil));

	dp[0] = 0; dp[1] = (scobil[1] - scobil[0]) % mod;
	for (int i = 2; i < n; ++i) {
		dp[i] = (3 * dp[i - 1] - 2 * dp[i - 2]) % mod + mod;
		dp[i] = (dp[i] + (exp2(i) - 1) * (scobil[i] - scobil[i - 1])) % mod;
	}
	cout << dp[n - 1];
}