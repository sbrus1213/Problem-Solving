// BOJ 10851 Cake
// Algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll	long long
#define BtoE(vec) vec.begin(), vec.end()

struct Point {
	ll x, y;

	Point operator - (Point tmp) {
		return { x - tmp.x, y - tmp.y };
	}
};
Point cri;

ll ccw(Point p1, Point p2, Point p3) {
	p2 = p2 - p1; p3 = p3 - p1;
	ll res = (ll)p2.x * (ll)p3.y - (ll)p3.x * (ll)p2.y;

	return res;
}

ll find_area(vector<Point>& point) {
	int l = point.size();
	ll res = 0;

	for (int i = 1; i < l - 1; ++i) {
		res += ccw(point[0], point[i], point[(i + 1) % l]);
	}

	return res;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, tidx;
	double portion, partial_area = 0, s = 2, e = 1000, mid = (s + e) / 2;
	Point tmp = { (ll)1e9, (ll)1e9 };
	vector<Point> point;
	ll area;

	cin >> portion >> n;
	point.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> point[i].x >> point[i].y;
	}

	area = find_area(point) / 2;
	for (int i = 0; i < n; ++i) {
		partial_area += (double)abs(ccw(point[i], point[(i + 1) % n], point[(i + 2) % n])) / 2;
	}

	while (e - s >= 0.000001) {
		if (area - (partial_area / (mid * mid)) <= area * portion) {
			s = mid;  mid = (s + e) / 2;
		}
		else {
			e = mid; mid = (s + e) / 2;
		}
	}

	cout << fixed;
	cout.precision(7);
	cout << mid;
}