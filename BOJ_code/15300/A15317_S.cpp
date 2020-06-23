// BOJ 15317 동방 보수
// binary search & greedy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; ll x; cin >> n >> m >> x;

	vector<ll> cost(n);
	for (ll& x : cost) cin >> x;
	sort(cost.begin(), cost.end());

	vector<ll> bgt(m);
	for (ll& x : bgt) cin >> x;
	sort(bgt.begin(), bgt.end());

	int low = 0, high = min(n, m) + 1;
	while (low + 1 < high) {
		int mid = (low + high) / 2;

		ll sum = 0;
		for (int i = 0; i < mid; ++i)
			sum += (bgt[m - mid + i] > cost[i] ? 0 : cost[i] - bgt[m - mid + i]);

		if (sum <= x) low = mid;
		else high = mid;
	}

	cout << low;
}