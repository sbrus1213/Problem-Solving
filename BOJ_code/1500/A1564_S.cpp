// BOJ 1564 팩토리얼5
// 수학

#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 1e8;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	int c = 0;
	for (int i = 5; i <= n; i+=5) {
		int t = i;
		while (t % 5 == 0) t /= 5, c++;
	}

	ll res = 1;
	for (ll i = 1; i <= n; ++i) {
		ll t = i;
		while (t > 1 && c && t % 2 == 0) {
			t /= 2;
			c--;
		}
		while (t % 5 == 0) t /= 5;
		res = (res * t) % mod;
	}
	cout.width(5);
	cout.fill('0');
	cout << res % 100000;
}