// BOJ 15318 새로운 수열
// 수학

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<ll> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<ll> b(n);
	for (ll i = 0; i < n; ++i) b[0] += (i % 2 ? -1LL : 1LL) * (i + 1) * a[i];

	ll tmp = 0;
	for (int i = 0; i < n; ++i) tmp += (i % 2 ? -1LL : 1LL) * a[i];
	for (int i = 1; i < n; ++i) {
		b[i] = -b[i - 1] + tmp + (n % 2 ? 1LL : -1LL) * n * a[i - 1];
		tmp = -tmp + a[i - 1] + (n % 2 ? 1LL : -1LL) * a[i - 1];
	}

	for (ll bb : b) cout << bb << ' ';
}