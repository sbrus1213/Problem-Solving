// BOJ 2261 가장 가까운 두 점
// sweeping algorithm

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
using pii = pair<int, int>;
#define x first
#define y second
const int inf = 100001;

int dist(pii a, pii b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<pii > P(n);
	for (int i = 0; i < n; ++i) cin >> P[i].x >> P[i].y;
	sort(P.begin(), P.end());

	int ans = dist(P[0], P[1]), last = 0;
	set<pii > dic;
	dic.insert({ P[0].y, P[0].x });
	dic.insert({ P[1].y, P[1].x });
	for (int i = 2; i < n; ++i) {
		pii cur = P[i];
		while (last < i) {
			int dx = cur.x - P[last].x;
			if (dx * dx <= ans) break;
			dic.erase({ P[last].y, P[last].x });
			last++;
		}
		int d = sqrt(ans) + 1;
		auto low = dic.lower_bound({ cur.y - d, -inf });
		auto high = dic.upper_bound({ cur.y + d, inf });
		for (auto it = low; it != high; ++it)
			ans = min(ans, dist({ it->second, it->first }, cur));
		dic.insert({ cur.y, cur.x });
	}
	cout << ans;
}