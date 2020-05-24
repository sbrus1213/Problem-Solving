// BOJ 15427 Greeting Card
// 수학 & hashing

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<pii> p(n);
	for (int i = 0; i < n; ++i)
		cin >> p[i].first >> p[i].second;
	sort(p.begin(), p.end());

	ll di[] = { 0,0, 2018,  -2018, 1118, 1118, -1118, -1118, 1680, 1680, -1680, -1680 },
		dj[] = { 2018, -2018, 0, 0, 1680, -1680, 1680, -1680, 1118, -1118, 1118, -1118 };
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		pii cur = p[i];
		for (int k = 0; k < 12; ++k) {
			pii nxt = pii(cur.first + di[k], cur.second + dj[k]);
			int idx = lower_bound(p.begin(), p.end(), nxt) - p.begin();
			if (idx < p.size() && p[idx] == nxt) ans++;
		}
	}
	cout << ans / 2;
}