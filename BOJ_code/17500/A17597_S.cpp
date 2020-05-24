// BOJ 17597 Zipline
// 수학 기하

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		double w, g, h, r; cin >> w >> g >> h >> r;
		cout << fixed;
		cout.precision(8);
		cout << sqrt((g - h) * (g - h) + (w * w)) << ' ';
		cout << sqrt((g + h - 2 * r) * (g + h - 2 * r) + (w * w)) << '\n';
	}
}