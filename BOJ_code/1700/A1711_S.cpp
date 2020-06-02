// BOJ 1711 직각 삼각형
// 기하

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

inline bool inner(pii a, pii b) {
	return (a.first * b.first + a.second * b.second ? 1 : 0);
}
pii operator - (pii a, pii b) {
	return pii(a.first - b.first, a.second - b.second);
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<pii> P(n);
	for (auto& p : P) cin >> p.first >> p.second;

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				pii l1 = P[i] - P[j];
				pii l2 = P[i] - P[k];
				pii l3 = P[j] - P[k];
				if (l1.second * l3.first == l1.first * l3.second) continue;
				if (inner(l1, l2) && inner(l1, l3) && inner(l2, l3)) continue;
				ans++;
			}
		}
	}
	cout << ans;
}