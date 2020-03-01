// BOJ 3878 Á¡ ºÐ¸®
// Convex Hull & CCW

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

struct Point {
	int x, y;

	Point operator- (const Point tmp) {
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

void input(vector<Point>& point) {
	int n = point.size(), cri_idx;

	cri = { 10001, 10001 };
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
}

void graham_scan(vector<Point>& point, vector<int>& convex_hull) {
	int l = point.size();

	if (l > 0) convex_hull.push_back(0);
	if (l > 1) convex_hull.push_back(1);
	if (l <= 2) return;

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
	convex_hull.push_back(0);
}

bool is_on_line(Point p, Point p1, Point p2) {
	if (ccw(p1, p, p2)) return false;
	else {
		if (p1.x == p2.x) {
			if (min(p1.y, p2.y) <= p.y && p.y <= max(p1.y, p2.y)) return true;
			return false;
		}
		else {
			if (min(p1.x, p2.x) <= p.x && p.x <= max(p1.x, p2.x)) return true;
			return false;
		}
	}
}

bool is_cross(Point l1_x, Point l1_y, Point l2_x, Point l2_y) {
	int ccw1 = ccw(l1_y, l1_x, l2_x) * ccw(l1_y, l1_x, l2_y),
		ccw2 = ccw(l2_y, l2_x, l1_x) * ccw(l2_y, l2_x, l1_y);

	if (ccw1 <= 0 && ccw2 <= 0) {
		if (!ccw1 && !ccw2) {
			if (l1_x.x == l1_y.x) {
				if (max(l1_x.y, l1_y.y) < min(l2_x.y, l2_y.y)) return false;
				if (max(l2_x.y, l2_y.y) < min(l1_x.y, l1_y.y)) return false;

				return true;
			}
			else {
				if (max(l1_x.x, l1_y.x) < min(l2_x.x, l2_y.x)) return false;
				if (max(l2_x.x, l2_y.x) < min(l1_x.x, l1_y.x)) return false;

				return true;
			}
		}
		else return true;
	}
	else return false;
}

bool is_overlap(vector<Point>& pt_a, vector<int>& ch_a, vector<Point>& pt_b, vector<int>& ch_b) {
	int la = ch_a.size(), lb = ch_b.size();

	if (la == 1 && lb == 1) return false;

	if (la == 1) {
		Point p = pt_a[ch_a[0]];

		for (int i = 0; i < lb - 1; ++i) {
			if (is_on_line(p, pt_b[ch_b[i]], pt_b[ch_b[i + 1]])) return true;
		}

		return false;
	}
	if (lb == 1) {
		Point p = pt_b[ch_b[0]];

		for (int i = 0; i < la - 1; ++i) {
			if (is_on_line(p, pt_a[ch_a[i]], pt_a[ch_a[i + 1]])) return true;
		}

		return false;
	}

	for (int i = 0; i < la - 1; ++i) {
		Point p1 = pt_a[ch_a[i]], p2 = pt_a[ch_a[i + 1]];

		for (int j = 0; j < lb - 1; ++j) {
			Point p3 = pt_b[ch_b[j]], p4 = pt_b[ch_b[j + 1]];

			if (is_cross(p1, p2, p3, p4)) return true;
		}
	}

	return false;
}

bool is_inside(vector<Point>& pt_a, vector<int>& ch_a, vector<Point>& pt_b, vector<int>& ch_b) {
	int la = ch_a.size(), lb = ch_b.size(), temp;

	if (lb < 3) return false;

	for (int i = 0; i < la; ++i) {
		int tmp;
		Point p = pt_a[ch_a[i]];

		for (int j = 0; j < lb - 1; ++j) {
			Point p1 = pt_b[ch_b[j]], p2 = pt_b[ch_b[j + 1]];

			if (!j) tmp = ccw(p1, p2, p);
			else if (tmp != ccw(p1, p2, p))
				return false;
		}

		if (!i) temp = tmp;
		else if (temp != tmp)
			return false;
	}

	return true;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;

	cin >> tc;

	while (tc--) {
		int n, m, cri_idx;
		vector<Point> black, white;
		vector<int> black_convex_hull, white_convex_hull;

		cin >> n >> m;
		black.resize(n);
		white.resize(m);

		input(black);
		input(white);

		graham_scan(black, black_convex_hull);
		graham_scan(white, white_convex_hull);

		if (is_overlap(black, black_convex_hull, white, white_convex_hull)) cout << "NO\n";
		else if (is_inside(black, black_convex_hull, white, white_convex_hull)) cout << "NO\n";
		else if (is_inside(white, white_convex_hull, black, black_convex_hull)) cout << "NO\n";
		else cout << "YES\n";
	}
}