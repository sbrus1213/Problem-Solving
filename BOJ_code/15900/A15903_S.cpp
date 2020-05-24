// BOJ 15903 카드 합체 놀이
// greedy & heap

#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	priority_queue<ll, vector<ll>, greater<ll>> pq;
	while (n--) {
		ll x; cin >> x;
		pq.push(x);
	}

	while (m--) {
		ll a = pq.top(); pq.pop();
		ll b = pq.top(); pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}

	ll ans = 0;
	while (!pq.empty()) {
		ans += pq.top(); pq.pop();
	}
	cout << ans;
}