// BOJ 2492 º¸¼®
// plane sweeping

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, t, k; cin >> n >> m >> t >> k;

	vector<pii > p(t);
	vector<int> x(t), y(t);
	for (int i = 0; i < t; ++i) {
		cin >> x[i] >> y[i];
		p[i] = { x[i], y[i] };
	}

	int xcnt = 0, ycnt = 0;
	sort(x.begin(), x.end()); sort(y.begin(), y.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	y.erase(unique(y.begin(), y.end()), y.end());
	xcnt = x.size(), ycnt = y.size();

	int ans = -1, ax = 0, ay = 0;
	for (int i = 0; i < xcnt; ++i) {
		for (int j = 0; j < ycnt; ++j) {
			int _i = x[i], _j = y[j], res = 0;
			if (_i + k > n) _i = n - k;
			if (_j + k > m) _j = m - k;
			if (i < 0 || j < 0) continue;
			for (int l = 0; l < t; ++l) {
				if (p[l].first < _i || p[l].first > _i + k) continue;
				if (p[l].second < _j || p[l].second > _j + k) continue;
				res++;
			}
			if (res > ans) {
				ans = res;
				ax = _i, ay = _j + k;
			}
		}
	}
	cout << ax << ' ' << ay << '\n' << ans;
}