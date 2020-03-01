// BOJ 9240 로버트 후드
// ccw & convex hull & rotating calipers

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using pii = pair<int, int>;
#define x first
#define y second

int n;
pii xx, yy;
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
		return a.x - P[0].x < b.x - P[0].x;
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
int ccw_(pii a, pii b, pii c, pii d) {
	return ccw({ 0, 0 }, { b.x - a.x, b.y - a.y }, { d.x - c.x, d.y - c.y });
}
int dist(pii a, pii b) {
	pii c = { a.x - b.x,a.y - b.y };
	return c.x * c.x + c.y * c.y;
}
int rotating_calipers() {
	int m = CH.size();
	int ret = -1;
	for (int i = 0, j = 1; i < m; ++i) {
		while (ccw_(P[CH[i]], P[CH[(i + 1) % m]], P[CH[j]], P[CH[(j + 1) % m]]) > 0)
			j = (j + 1) % m;
		int tmp = dist(P[CH[i]], P[CH[j]]);
		ret = max(ret, tmp);
	}
	return ret;
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
	sort(P.begin() + 1, P.end(), cmp);
	graham_scan();
	int res = rotating_calipers();
	cout << fixed;
	cout.precision(7);
	cout << sqrt(res);
}