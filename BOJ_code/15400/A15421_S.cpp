// BOJ 15421 Birthday Cake
// geometry

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;
};
struct Line {
	int a, b, c;
};

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; double r; cin >> n >> m >> r;

	vector<Point> p(n);
	for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
	vector<Line> l(m);
	for (int i = 0; i < m; ++i) cin >> l[i].a >> l[i].b >> l[i].c;

	int match = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			auto l1 = l[i], l2 = l[j];
			if (l1.a * l2.b == l2.a * l1.b) continue;
			double y = (double)(l1.b * l2.c - l2.b * l1.c) / (double)(l1.a * l2.b - l2.a * l1.b);
			double x = (double)(l1.a * l2.c - l2.a * l1.c) / (double)(l2.a * l1.b - l1.a * l2.b);
			if (x * x + y * y < r * r) match++;
		}
	}

	if (m + 1 + match != n) {
		cout << "no";
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			bool flag = false;
			for (int k = 0; k < m; ++k) {
				int val1 = l[k].a * p[i].x + l[k].b * p[i].y + l[k].c;
				int val2 = l[k].a * p[j].x + l[k].b * p[j].y + l[k].c;
				if (val1 * val2 < 0) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				cout << "no";
				return 0;
			}
		}
	}

	cout << "yes";
}