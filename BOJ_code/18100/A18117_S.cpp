// BOJ 18117 ºÐ¼ö

#include <iostream>
using namespace std;
using ll = long long;

ll multiple_mod(ll x, ll y, ll mod) {
	ll res = 0;
	while (y) {
		if (y % 2) res = (res + x) % mod;
		x = (x * 2) % mod;
		y /= 2;
	}
	return res;
}

ll multiple_tens(ll a, ll i, ll mod) {
	ll t = 10, res = 1;
	while (i) {
		if (i % 2)
			res = multiple_mod(res, t, mod);
		t = multiple_mod(t, t, mod);
		i /= 2;
	}
	res = multiple_mod(res, a, mod);
	return res;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		ll a, b, i, n, tmp;

		cin >> a >> b >> i >> n;
		tmp = multiple_tens(a, i - 1, b);

		for (int j = 0; j < n; ++j) {
			cout << (int)(((float)tmp / b) * 10);
			tmp = multiple_mod(tmp, 10, b);
		}
		cout << '\n';
	}
}