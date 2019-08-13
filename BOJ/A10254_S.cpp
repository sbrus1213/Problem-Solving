// BOJ 10254 고속도로
// CCW & Convex Hull & Rotating calipers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll	long long

struct Point {
	int x, y;

	Point operator- (const Point tmp) {
		return { x - tmp.x, y - tmp.y };
	}
	Point operator+ (const Point tmp) {
		return { x + tmp.x, y + tmp.y };
	}
};
Point cri;

int ccw(Point p1, Point p2, Point p3) {
	p2 = p2 - p1; p3 = p3 - p1;
	ll res = (ll)p2.x * (ll)p3.y - (ll)p3.x * (ll)p2.y;

	if (res) return (res > 0 ? 1 : -1);
	else return res;
}

bool gradient_compare(Point a, Point b) {
	if (ccw(cri, a, b) == 1) return true;
	else if (ccw(cri, a, b) == -1) return false;
	else if ((a - cri).x < (b - cri).x) return true;
	else return false;
}
void gradient_sort(vector<Point>& point) {
	sort(point.begin() + 1, point.end(), gradient_compare);
}

void graham_scan(vector<Point>& point, vector<int>& convex_hull) {
	int l = point.size();

	convex_hull.push_back(0);
	convex_hull.push_back(1);

	for (int i = 2; i < l; ++i) {
		while (convex_hull.size() >= 2) {
			int p2 = convex_hull.back();
			convex_hull.pop_back();
			int p1 = convex_hull.back();

			if (ccw(point[p1], point[p2], point[i]) == 1) {
				convex_hull.push_back(p2);
				break;
			}
		}

		convex_hull.push_back(i);
	}
}

void rotating_calipers(vector<Point>& point, vector<int>& convex_hull, vector<int>& farthest) {
	int l = convex_hull.size(), far = 2;

	if (l == 2) {
		farthest.push_back(convex_hull[1]);
		farthest.push_back(convex_hull[0]);
		return;
	}

	for (int i = 0; i < l; ++i) {
		if (i + 1 == far) far = (far + 1) % l;
		Point p1 = point[convex_hull[i]], p2 = point[convex_hull[(i + 1) % l]],
			p3 = point[convex_hull[far]], p4 = point[convex_hull[(far + 1) % l]];

		while (ccw(p1, p2, p4 - p3 + p1) > 0) {
			far = (far + 1) % l;

			p3 = point[convex_hull[far]], p4 = point[convex_hull[(far + 1) % l]];
		}

		farthest.push_back(convex_hull[far]);
	}
}

ll distance(Point a, Point b) {
	Point diff = b - a;

	return ((ll)(diff).x * (ll)(diff).x) + ((ll)(diff).y * (ll)(diff).y);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;

	cin >> tc;

	while (tc--) {
		int n, cri_idx;
		vector<Point> point;
		vector<int> convex_hull, farthest;

		cin >> n;
		point.resize(n);

		cri = { (int)1e8, (int)1e8 };
		for (int i = 0; i < n; ++i) {
			int x, y;

			cin >> x >> y;
			point[i] = { x, y };

			if (cri.x > x || (cri.x == x && cri.y > y)) {
				cri = { x, y };
				cri_idx = i;
			}
		}

		swap(point[cri_idx], point[0]);
		gradient_sort(point);

		graham_scan(point, convex_hull);

		rotating_calipers(point, convex_hull, farthest);

		ll res = 0, ans;
		for (int i = 0; i < convex_hull.size(); ++i) {
			ll tmp = distance(point[convex_hull[i]], point[farthest[i]]);

			if (res < tmp) {
				res = tmp;
				ans = i;
			}
		}

		cout << point[convex_hull[ans]].x << ' ' << point[convex_hull[ans]].y << ' ' << point[farthest[ans]].x << ' ' << point[farthest[ans]].y << '\n';
	}
}