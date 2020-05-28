// BOJ 18917 수열과 쿼리 38
// 수학

#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int q; cin >> q;
	ll sum = 0, eor = 0;
	while (q--) {
		int c; cin >> c;
		if (c == 1) {
			ll x; cin >> x;
			sum += x; eor ^= x;
		}
		if (c == 2) {
			ll x; cin >> x;
			sum -= x; eor ^= x;
		}
		if (c == 3) cout << sum << '\n';
		if (c == 4) cout << eor << '\n';
	}
}