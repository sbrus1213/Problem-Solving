// BOJ 1654 랜선 자르기
// Binary search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	ll n, k; cin >> n >> k;

	vector<ll> lan(n);
	for (ll& x : lan) cin >> x;

	ll l = 1, r = *max_element(lan.begin(), lan.end()) + 1;
	while (l + 1 < r) {
		ll mid = (l + r) / 2;

		ll c = 0;
		for (ll x : lan) c += x / mid;

		if (c >= k) l = mid;
		else r = mid;
	}
	cout << l;
}