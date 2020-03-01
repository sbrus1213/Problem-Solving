// BOJ 14730 ÚºÝÑËÎßãÑº (large)
// exponentiation by squaring

#include <iostream>
using namespace std;
using ll = long long;
#define div (ll)(1e9 + 7)

int exp_2(int x) {
	ll a = 2, res = 1;

	while (x) {
		if (x % 2)
			res = (res * a) % div;
		x >>= 1;
		a = (a * a) % div;
	}
	return res;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	ll c, k, res = 0;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c >> k;
		if (k) res = (res + (((c * k) % div) * exp_2(k - 1)) % div) % div;
	}
	cout << res;
}