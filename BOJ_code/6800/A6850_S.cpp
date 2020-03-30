// BOJ 6850 cows
// ccw & convex hull

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
#define x first
#define y second

double ccw(pii a, pii b, pii c) {
	b = pii(b.x - a.x, b.y - a.y);
	c = pii(c.x - a.x, c.y - a.y);
	int ret = b.x * c.y - b.y * c.x;
	return (double)ret;
}
int n;
vector<pii > P;
vector<int> CH;
void graham_scan() {
	for (int i = 0; i < n; ++i) {
		while (CH.size() >= 2) {
			int sz = CH.size();
			if (ccw(P[CH[sz - 2]], P[CH[sz - 1]], P[i]) < 1)
				CH.pop_back();
			else break;
		}
		CH.push_back(i);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		P.push_back({ x, y });
	}
	swap(P[0], *min_element(P.begin(), P.end()));
	sort(P.begin() + 1, P.end(), [&](pii a, pii b) {
		if (ccw(P[0], a, b) == 0) return (a.x == b.x ? a.y - P[0].y < b.y - P[0].y : a.x - P[0].x < b.x - P[0].x);
		return ccw(P[0], a, b) > 0;
		});
	graham_scan();
	double ans = 0;
	for (int i = 1; i < CH.size() - 1; ++i)
		ans += ccw(P[CH[0]], P[CH[i]], P[CH[i + 1]]) / 2;
	cout << (int)(ans / 50);
}