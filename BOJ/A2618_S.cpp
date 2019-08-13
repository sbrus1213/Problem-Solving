// BOJ 2618 °æÂûÂ÷
// Dynamic Programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e9

struct Point {
	int x, y;

	Point() {}
	Point(int x, int y) :x(x), y(y) {}
};

int dist(Point a, Point b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}
int dp[1001][1001];
Point from[1001][1001];
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	int n, w;
	Point point[1001];

	cin >> n >> w;

	for (int i = 1; i <= w; ++i) cin >> point[i].x >> point[i].y;

	for (int i = 0; i <= w; ++i)
		for (int j = 0; j <= w; ++j)
			dp[i][j] = INF;

	dp[0][1] = 2 * n - (point[1].x + point[1].y);
	dp[1][0] = (point[1].x + point[1].y) - 2;
	from[0][1] = from[1][0] = { 0, 0 };

	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < w; ++j) {
			if (i == j) continue;

			int next = max(i, j) + 1, tmp;

			if (i) tmp = dp[i][j] + dist(point[next], point[i]);
			else tmp = dp[i][j] + dist(point[next], Point(1, 1));
			if (dp[next][j] > tmp) {
				dp[next][j] = tmp;
				from[next][j] = { i, j };
			}

			if (j) tmp = dp[i][j] + dist(point[next], point[j]);
			else tmp = dp[i][j] + dist(point[next], Point(n, n));
			if (dp[i][next] > tmp) {
				dp[i][next] = tmp;
				from[i][next] = { i, j };
			}
		}
	}

	int res = INF, tmp;
	Point pre;
	vector<int> ans;
	for (int i = 0; i < w; ++i) {
		if (res > dp[i][w]) {
			res = dp[i][w];
			pre = from[i][w];
			tmp = 2;
		}
		if (res > dp[w][i]) {
			res = dp[w][i];
			pre = from[w][i];
			tmp = 1;
		}
	}

	ans.push_back(tmp);
	for (int i = w - 1; i > 0; --i) {
		if (pre.x == i) ans.push_back(1);
		else ans.push_back(2);

		pre = from[pre.x][pre.y];
	}

	cout << res << '\n';
	for (int i = w - 1; i >= 0; --i)
		cout << ans[i] << '\n';
}