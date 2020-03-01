// BOJ 10903 Wall Construction
// Convex Hull & CCW

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using pii = pair<int, int>;
#define x first
#define y second
const double PI = 2 * acos(0.0);
int n;
vector<pii > P;
vector<int> CH;

int ccw(pii a, pii b, pii c) {
	b = { b.x - a.x , b.y - a.y };
	c = { c.x - a.x, c.y - a.y };
	int ret = b.x * c.y - b.y * c.x;
	if (ret > 0) return 1;
	else if (ret == 0) return 0;
	else return -1;
}
bool cmp(pii& a, pii& b) {
	if (ccw(P[0], a, b) == 0)
		return (a.x != b.x ? a.x - P[0].x < b.x - P[0].x : a.y - P[0].y < b.y - P[0].y);
	else return ccw(P[0], a, b) == 1;
}
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
double dist(pii a, pii b) {
	pii c = { a.x - b.x, a.y - b.y };
	return sqrt(c.x * c.x + c.y * c.y);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int r;
	cin >> n >> r;
	for (int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		P.push_back({ x, y });
	}
	swap(P[0], *min_element(P.begin(), P.end()));
	sort(P.begin() + 1, P.end(), cmp);
	graham_scan();
	int v = CH.size();
	double ans = 0;
	for (int i = 0; i < v; ++i)
		ans += dist(P[CH[i]], P[CH[(i + 1) % v]]);
	ans += 2 * PI * r;
	cout << fixed;
	cout.precision(7);
	cout << ans;
}