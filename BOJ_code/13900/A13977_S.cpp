// BOJ 13977 이항 계수와 쿼리
// combinatorics & fermat's litter theorem & exponentiation by squaring

#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll exp(ll x, ll times) {
	ll res = 1;
	while (times) {
		if (times % 2) res = (res * x) % mod;
		times >>= 1;
		x = (x * x) % mod;
	}
	return res;
}

int fact[4000001], fact_inv[4000001];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	fact[0] = fact_inv[0] = 1;
	for (int i = 1; i <= 4000000; ++i) fact[i] = (1LL * fact[i - 1] * i) % mod;
	fact_inv[4000000] = exp(fact[4000000], mod - 2);
	for (int i = 3999999; i > 0; --i) fact_inv[i] = (1LL * fact_inv[i + 1] * (i + 1)) % mod;

	int m; cin >> m;
	while (m--) {
		int n, k; cin >> n >> k;
		cout << ((1LL * fact[n] * fact_inv[k]) % mod * fact_inv[n - k]) % mod << '\n';
	}
}