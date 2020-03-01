// BOJ 11401 이항 계수3
// combinatorics & exponentiation by squaring

#include <iostream>
using namespace std;
using ll = long long;
const int mod = 1000000007;

ll exp_sq(ll x, ll times) {
	ll res = 1;
	while (times) {
		if (times % 2) res = (res * x) % mod;
		times >>= 1;
		x = (x * x) % mod;
	}
	return res;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	ll tmp = 1, res = 1;

	cin >> n >> k;
	for (ll i = 1; i <= k; ++i) tmp = (tmp * i) % mod;
	for (ll i = 1; i <= n - k; ++i) tmp = (tmp * i) % mod;

	for (ll i = 1; i <= n; ++i) res = (res * i) % mod;
	cout << (res * exp_sq(tmp, mod - 2)) % mod;
}