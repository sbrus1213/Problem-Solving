// BOJ 1300 k¹øÂ° ¼ö
// Binary search

#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n, k; cin >> n >> k;

	ll low = 1, high = n * n + 1;
	while (low + 1 < high) {
		ll mid = (low + high) / 2;

		ll t = 0;
		for (int i = 1; i <= n; ++i) {
			t += min(n, (mid - 1) / i);
		}
		if (t >= k)high = mid;
		else low = mid;
	}

	cout << low;
}