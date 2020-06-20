// BOJ 2805 나무 자르기
// Binary search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n, m; cin >> n >> m;

	vector<ll> hgt(n);
	for (ll& x : hgt) cin >> x;

	ll l = 0, r = *max_element(hgt.begin(), hgt.end()) + 1;
	while (l + 1 < r) {
		ll mid = (l + r) / 2;

		ll sum = 0;
		for (ll x : hgt)
			sum += (x > mid ? x - mid : 0);

		if (sum >= m) l = mid;
		else r = mid;
	}
	cout << l;
}