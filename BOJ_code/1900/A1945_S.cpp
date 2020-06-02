// BOJ 1945 직사각형
// 기하 & sort

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
	int x, y, fl;
};

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<point> P;
	for (int i = 0; i < n; ++i) {
		int xbl, ybl, xtr, ytr;
		cin >> xbl >> ybl >> xtr >> ytr;
		P.push_back({ xbl, ytr, -1 });
		P.push_back({ xtr, ybl, 1 });
	}
	sort(P.begin(), P.end(), [&](point a, point b) {
		double ad = 1.0 * a.y / a.x, bd = 1.0 * b.y / b.x;
		if (ad == bd) return a.fl > b.fl;
		return ad < bd;
		});

	int res = 0, ans = 0;
	for (point& p : P) {
		res += p.fl;
		ans = max(ans, res);
	}
	cout << ans;
}