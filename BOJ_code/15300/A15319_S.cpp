// BOJ 15319 동혁이의 생일선물
// bit 수학

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;

	ll ans = 0;
	while (tc--) {
		int n, k; cin >> n >> k;

		vector<ll> exp(30, 1);
		for (int i = 1; i < 30; ++i)
			exp[i] = (exp[i - 1] * n) % mod;

		ll tmp = 0;
		for (int i = 0; i < 30; ++i) {
			if (k % 2)
				tmp = (tmp + exp[i]) % mod;
			k >>= 1;
		}

		ans = (ans + tmp) % mod;
	}
	cout << ans;
}