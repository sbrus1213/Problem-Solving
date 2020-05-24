// BOJ 15424 Cat and Mice
// Binary search & TSP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const double inf = 1e10;

struct pos {
	double xx, yy;
};

double dp[1 << 15][15];

inline double dist(pos a, pos b) {
	return sqrt((a.xx - b.xx) * (a.xx - b.xx) + (a.yy - b.yy) * (a.yy - b.yy));
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<pos> cat(n);
	vector<int> duck(n);
	for (int i = 0; i < n; ++i)
		cin >> cat[i].xx >> cat[i].yy >> duck[i];

	string s; cin >> s;
	double rate = 0.0;
	if (s.size() == 2) rate = (s[1] - '0') * 10;
	else rate = (s[1] - '0') * 10 + s[2] - '0';
	rate /= 100;

	vector<double> rpow(n + 1);
	rpow[0] = 1.0;
	for (int i = 1; i <= n; ++i) rpow[i] = rpow[i - 1] * rate;

	double l = 1e-4, r = inf, ep = 1e-4, ans = inf;
	int cnt = 0;
	while (r - l > ep && cnt <= 500) {
		for (int i = 0; i < (1 << n); ++i)
			for (int j = 0; j < n; ++j)
				dp[i][j] = inf;

		double mid = (l + r) / 2;
		cnt++;

		for (int i = 0; i < n; ++i)
			if (dist(cat[i], { 0, 0 }) / mid <= duck[i])
				dp[1 << i][i] = dist(cat[i], { 0, 0 }) / mid;

		for (int i = 1; i < (1 << n); ++i) {
			int c = 0, t = i;
			while (t) { if (t % 2)c++; t /= 2; }
			for (int j = 0; j < n; ++j) {
				if (!(i & (1 << j))) continue;
				for (int k = 0; k < n; ++k) {
					if (i & (1 << k)) continue;
					double d = dist(cat[j], cat[k]);
					double v = mid * rpow[c];
					double t = d / v;
					if (dp[i][j] + t > duck[k]) continue;
					dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + t);
				}
			}
		}

		double res = inf;
		for (int i = 0; i < n; ++i) res = min(res, dp[(1 << n) - 1][i]);

		if (res != inf) {
			r = mid;
			ans = min(ans, res);
		}
		else l = mid + ep;
	}

	cout << fixed;
	cout.precision(6);
	cout << r;
}