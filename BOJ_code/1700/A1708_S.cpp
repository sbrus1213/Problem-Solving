// BOJ 1708 ÄÁº¤½º Çæ
// Convex Hull & CCW

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

int n;
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
	sort(P.begin() + 1, P.end(), cmp);
	graham_scan();
	cout << CH.size();
}