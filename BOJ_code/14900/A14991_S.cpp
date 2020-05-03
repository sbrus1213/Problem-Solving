// BOJ 14991 Disastrous Doubling
// ±¸Çö

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 60;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	ll ans = 1LL;
	bool suc = false;
	for (int i = 0; i < n; ++i) {
		ll b; cin >> b;
		ans = ans * 2 - b;
		if (ans >= inf) suc = true;

		if (suc) ans = (ans % mod + mod) % mod;
		else if (ans < 0) {
			cout << "error";
			return 0;
		}
	}
	cout << (ans % mod + mod) % mod;
}