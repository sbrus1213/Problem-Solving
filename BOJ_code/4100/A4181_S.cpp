// BOJ 4181 Convex Hull
// sort - convex hull

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int ccw(pii a, pii b, pii c) {
	b = pii(b.first - a.first, b.second - a.second);
	c = pii(c.first - a.first, c.second - a.second);
	ll ret = b.first * c.second - b.second * c.first;
	if (ret > 0) return 1;
	else if (!ret) return 0;
	return -1;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<pii> P;
	for (int i = 0; i < n; ++i) {
		ll x, y; char c; cin >> x >> y >> c;
		if (c == 'Y') P.push_back({ x, y });
	}
	swap(P[0], *min_element(P.begin(), P.end()));
	sort(P.begin() + 1, P.end(), [&](pii a, pii b) {
		if (ccw(P[0], a, b) == 0) return a.first == b.first ? a.second < b.second : a.first < b.first;
		return ccw(P[0], a, b) > 0;
		});
	int idx;
	for (idx = P.size() - 1; idx > 0; --idx)
		if (ccw(P[0], P[idx], P[idx - 1]) != 0) break;
	reverse(P.begin() + idx, P.end());
	cout << P.size();
	for (int i = 0; i < P.size(); ++i)
		cout << '\n' << P[i].first << ' ' << P[i].second;
}