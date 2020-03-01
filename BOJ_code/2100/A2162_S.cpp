// BOJ 2162 선분 그룹
// CCW

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Point {
	int x, y;
};
struct Line {
	Point p1, p2;
};

int par[3001];
Line line[3001];

int find(int x) {
	if (par[x] < 0) return x;
	return par[x] = find(par[x]);
}
void merge(int x, int y) {
	int px = find(x), py = find(y);

	if (px == py) return;

	par[px] += par[py];
	par[py] = px;
}

int ccw(Point v1, Point v2) {
	int res = v1.x * v2.y - v2.x * v1.y;

	if (res) return res > 0 ? 1 : -1;
	else return res;
}
bool cross(Line l1, Line l2) {
	int ccw1, ccw2;
	Point v[3];

	v[0] = { l1.p2.x - l1.p1.x,l1.p2.y - l1.p1.y };
	v[1] = { l2.p1.x - l1.p1.x,l2.p1.y - l1.p1.y };
	v[2] = { l2.p2.x - l1.p1.x,l2.p2.y - l1.p1.y };
	ccw1 = ccw(v[0], v[1]) * ccw(v[0], v[2]);

	v[0] = { l2.p2.x - l2.p1.x,l2.p2.y - l2.p1.y };
	v[1] = { l1.p1.x - l2.p1.x,l1.p1.y - l2.p1.y };
	v[2] = { l1.p2.x - l2.p1.x,l1.p2.y - l2.p1.y };
	ccw2 = ccw(v[0], v[1]) * ccw(v[0], v[2]);

	if (ccw1 <= 0 && ccw2 <= 0) {
		if (!ccw1 && !ccw2) {
			if (l1.p1.x == l1.p2.x) {
				if (min(l1.p1.y, l1.p2.y) > max(l2.p1.y, l2.p2.y)) return false;
				if (max(l1.p1.y, l1.p2.y) < min(l2.p1.y, l2.p2.y)) return false;
				return true;
			}
			else {
				if (min(l1.p1.x, l1.p2.x) > max(l2.p1.x, l2.p2.x)) return false;
				if (max(l1.p1.x, l1.p2.x) < min(l2.p1.x, l2.p2.x)) return false;
				return true;
			}
		}
		else return true;
	}
	else return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> line[i].p1.x >> line[i].p1.y >> line[i].p2.x >> line[i].p2.y;

	fill(par, par + 3001, -1);
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (find(i) != find(j))
				if (cross(line[i], line[j]))
					merge(i, j);

	int cnt = 0, res = 0;
	for (int i = 0; i < n; ++i)
		if (par[i] < 0) {
			++cnt;
			res = min(res, par[i]);
		}

	cout << cnt << '\n' << -res;
}