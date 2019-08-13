// BOJ 11758 CCW
// CCW

#include <iostream>
using namespace std;

struct vec {
	int x, y;
};

int ccw(vec v1, vec v2) {
	int res = (v1.x * v2.y) - (v1.y * v2.x);

	if (res) return res > 0 ? 1 : -1;
	else return 0;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x1, y1, z1, x2, y2, x3, y3;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	cout << ccw({ x2 - x1, y2 - y1 }, { x3 - x2, y3 - y2 });
}