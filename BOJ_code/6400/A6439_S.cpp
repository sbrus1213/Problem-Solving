// BOJ 6439 ±³Â÷
// CCW

#include <iostream>
#include <algorithm>
using namespace std;
#define ll	long long

struct Point {
	int x, y;

	Point operator- (const Point tmp) {
		return { x - tmp.x, y - tmp.y };
	}
};

int ccw(Point p1, Point p2, Point p3) {
	p2 = p2 - p1; p3 = p3 - p1;
	int res = (ll)p2.x * p3.y - (ll)p3.x * p2.y;

	if (res) return (res > 0 ? 1 : -1);
	else return res;
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

bool is_inside(Point* line, Point* square) {
	bool flag = true;

	if (!(min(square[0].x, square[2].x) <= line[0].x && line[0].x <= max(square[0].x, square[2].x))) flag = false;
	if (!(min(square[0].x, square[2].x) <= line[2].x && line[2].x <= max(square[0].x, square[2].x))) flag = false;
	if (!(min(square[0].y, square[2].y) <= line[0].y && line[0].y <= max(square[0].y, square[2].y))) flag = false;
	if (!(min(square[0].y, square[2].y) <= line[2].y && line[2].y <= max(square[0].y, square[2].y))) flag = false;

	return flag;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;

	cin >> tc;

	while (tc--) {
		bool flag = false;
		Point line[2], square[4];

		cin >> line[0].x >> line[0].y >> line[1].x >> line[1].y;

		cin >> square[0].x >> square[0].y >> square[2].x >> square[2].y;
		square[1] = { square[0].x, square[2].y };
		square[3] = { square[2].x ,square[0].y };

		for (int i = 0; i < 4; ++i) {
			if (is_cross(line[0], line[1], square[i], square[(i + 1) % 4])) {
				flag = true;
				break;
			}
		}

		if (is_inside(line, square)) flag = true;

		if (flag) cout << "T\n";
		else cout << "F\n";
	}
}