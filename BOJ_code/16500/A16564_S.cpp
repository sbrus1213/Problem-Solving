// BOJ 16564 히오스 프로게이머
// heap

#include <iostream>
#include <queue>
using namespace std;
#define ll	long long

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n, k;
	priority_queue<ll, vector<ll>, greater<ll> > pq;

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		pq.push(x);
	}

	ll minl = pq.top(), minc = 1;
	pq.pop();
	while (1) {
		while (minl == pq.top()) {
			pq.pop();
			minc++;
		}

		ll diff = pq.top() - minl;
		if (k - diff * minc <= 0) {
			minl += k / minc;
			break;
		}
		else {
			minl += diff;
			k -= diff * minc;
		}
	}

	cout << minl;
}