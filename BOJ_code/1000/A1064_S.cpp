// BOJ 1064 평행사변형
// 기하

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

inline double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	double x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	if ((y2 - y1) * (x3 - x2) == (x2 - x1) * (y3 - y2)) cout << -1;
	else {
		double l1 = 2 * (dist(x1, y1, x2, y2) + dist(x2, y2, x3, y3));
		double l2 = 2 * (dist(x1, y1, x3, y3) + dist(x2, y2, x3, y3));
		double l3 = 2 * (dist(x1, y1, x2, y2) + dist(x1, y1, x3, y3));
		cout << fixed;
		cout.precision(10);
		cout << max({ l1, l2, l3 }) - min({ l1, l2, l3 });
	}
}