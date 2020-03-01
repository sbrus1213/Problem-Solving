// BOJ 10254 고속도로
// CCW & Convex Hull & Rotating calipers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
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
	ll ret = 1LL * b.x * c.y - 1LL * b.y * c.x;
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
	CH.push_back(0); CH.push_back(1);

	for (int i = 2; i < n; ++i) {
		while (CH.size() >= 2) {
			int p2 = CH.back(); CH.pop_back();
			int p1 = CH.back();
			if (ccw(P[p1], P[p2], P[i]) == 1) {
				CH.push_back(p2);
				break;
			}
		}
		CH.push_back(i);
	}
}
int ccw_(pii a, pii b, pii c, pii d) {
	return ccw({ 0, 0 }, 
		{ b.x - a.x, b.y - a.y }, 
		{ d.x - c.x, d.y - c.y });
}
ll dist(pii a, pii b) {
	pii c = { a.x - b.x,a.y - b.y };
	return 1LL * c.x * c.x + 1LL * c.y * c.y;
}
void rotating_calipers() {
	int m = CH.size();
	ll ret = -1;
	for (int i = 0, j = 1; i < m; ++i) {
		// ccw_(a, b, c, d) : a->b 벡터와 c->d 벡터의 방향성
		while (ccw_(P[CH[i]], P[CH[(i + 1) % m]], 
			P[CH[j]], P[CH[(j + 1) % m]]) > 0) {
			j = (j + 1) % m;
		}
		ret = max(ret, dist(P[CH[i]], P[CH[j]]));
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		P.clear();
		for (int i = 0; i < n; ++i) {
			int x, y; cin >> x >> y;
			P.push_back({ x, y });
		}
		swap(P[0], *min_element(P.begin(), P.end()));
		sort(P.begin() + 1, P.end(), cmp);
		CH.clear();
		graham_scan();
		rotating_calipers();
		cout << xx.x << ' ' << xx.y << ' ' << yy.x << ' ' << yy.y << '\n';
	}
}