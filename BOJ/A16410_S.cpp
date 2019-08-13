// BOJ 16410 Goat Rope

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	double x, y, x1, y1, x2, y2, res;

	cin >> x >> y >> x1 >> y1 >> x2 >> y2;

	if (x >= x1 && x <= x2) {
		if (y >= y1 && y <= y2) {
			res = min(abs(x - x1), abs(x - x2));
			res = min(res, min(abs(y - y1), abs(y - y2)));
		}
		else {
			res = min(abs(y - y1), abs(y - y2));
		}
	}
	else if (y >= y1 && y <= y2) {
		res = min(abs(x - x1), abs(x - x2));
	}
	else {
		res = (x - x1) * (x - x1) + (y - y1) * (y - y1);
		res = min(res, (x - x2) * (x - x2) + (y - y1) * (y - y1));
		res = min(res, (x - x1) * (x - x1) + (y - y2) * (y - y2));
		res = min(res, (x - x2) * (x - x2) + (y - y2) * (y - y2));

		res = sqrt(res);
	}
	cout << fixed;
	cout.precision(4);
	cout << res;
}