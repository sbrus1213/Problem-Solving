// BOJ 1834 나머지와 몫이 같은 수
// 수학

#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	ll ans = 0;
	for (ll i = 0; i < n; ++i)
		ans += i + (ll)i * n;
	cout << ans;
}