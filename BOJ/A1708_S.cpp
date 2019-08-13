// BOJ 1708 ÄÁº¤½º Çæ
// Convex Hull & CCW

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

struct Point {
	int x, y;

	Point operator - (Point tmp) {
		return { x - tmp.x, y - tmp.y };
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

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, cri_idx;
	vector<Point> point;
	vector<int> convex_hull;

	cin >> n;
	point.resize(n);
	cri = { 40001, 40001 };

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

	cout << convex_hull.size();
}