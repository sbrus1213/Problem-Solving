// BOJ 13171 A
// exponentiation by squaring

#include <iostream>
using namespace std;
using ll = long long;
#define div (ll)(1e9 + 7)

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll a, x, res = 1;
	cin >> a >> x;

	a %= div;
	while (x) {
		if (x % 2)
			res = (res * a) % div;
		x >>= 1;
		a = (a * a) % div;
	}
	cout << res;
}