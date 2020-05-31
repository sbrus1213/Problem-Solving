// BOJ 2783 삼각 김밥
// 수학

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int x, y; cin >> x >> y;

	double ans = 1000.0 * x / y;

	int n; cin >> n;
	while (n--) {
		cin >> x >> y;
		ans = min(ans, 1000.0 * x / y);
	}

	cout << fixed;
	cout.precision(4);
	cout << ans;
}