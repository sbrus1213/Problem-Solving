// BOJ 15428 Imperfect GPS
// binary search

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using pdd = pair<double, double>;

double dist(pdd a, pdd b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, t; cin >> n >> t;

	vector<int> time(n);
	vector<pdd> pos(n);
	for (int i = 0; i < n; ++i)
		cin >> pos[i].first >> pos[i].second >> time[i];

	double tot = 0;
	for (int i = 1; i < n; ++i)
		tot += dist(pos[i], pos[i - 1]);

	pdd prv = pos[0];
	double gps = 0;
	for (int i = t; i < time.back(); i += t) {
		int idx = lower_bound(time.begin(), time.end(), i) - time.begin();
		if (time[idx] == i) {
			gps += dist(pos[idx], prv);
			prv = pos[idx];
		}
		else {
			idx--;
			int m = i - time[idx], n = time[idx + 1] - i, mn = time[idx + 1] - time[idx];
			pdd cur = pdd((pos[idx].first * n + pos[idx + 1].first * m) / mn, (pos[idx].second * n + pos[idx + 1].second * m) / mn);
			gps += dist(cur, prv);
			prv = cur;
		}
	}
	gps += dist(prv, pos.back());

	cout << fixed;
	cout.precision(6);
	cout << (tot - gps) * 100 / tot;
}