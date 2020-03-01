// BOJ 11758 CCW
// CCW

#include <iostream>
#include <utility>
using namespace std;
using pii = pair<int, int>;
#define x first
#define y second

int ccw(pii a, pii b, pii c) {
	b = { b.x - a.x, b.y - a.y };
	c = { c.x - a.x, c.y - a.y };
	int res = b.x * c.y - b.y * c.x;
	if (res) return res > 0 ? 1 : -1;
	return 0;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	pii a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	cout << ccw(a, b, c);
}