// BOJ 1016 제곱 ㄴㄴ 수
// 수학

#include <iostream>
using namespace std;
using ll = long long;

bool prime[1001001], chk[1000001];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	ll l, r; cin >> l >> r;

	for (ll i = 2; i *i <= r; ++i) {
		if (prime[i]) continue;
		for (ll j = 2; i * j <= r; ++j)
			prime[i * j] = 1;
	}

	ll cnt = r - l + 1;
	for (ll i = 2; i * i <= r; ++i) {
		if (prime[i]) continue;
		ll st = l / (i * i) * (i * i);
		if (st < l) st += (i * i);
		for (ll j = st - l; j <= r - l; j += (i * i))
			if (!chk[j]) chk[j] = 1, cnt--;
	}
	cout << cnt;
}