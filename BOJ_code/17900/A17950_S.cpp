// BOj 17950 스노우볼
// 수학

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll h, x;
vector<ll> pt;

void init() {
	pt[0] = 1;
	for (int i = 1; i <= h; ++i)
		pt[i] = (pt[i - 1] * x) % mod;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> h >> x;

	pt = vector<ll>(h + 1);
	init();

	ll ans = 0;
	for (int i = 1; i <= h; ++i) {
		ll c; cin >> c;
		ans = (ans + c * pt[i]) % mod;
	}
	cout << ans;
}