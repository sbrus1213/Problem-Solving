// BOJ 13299 Unusual Darts
// ccw

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using pdd = pair<double, double>;
#define x first
#define y second

double accw(pdd a, pdd b) {
	double res = a.x * b.y - b.x * a.y;
	if (res > 0) return 1;
	else if (res < 0) return -1;
	else return 0;
}
double ccw(pdd a, pdd b) {
	return a.x * b.y - b.x * a.y;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		vector<pdd> pos(8);
		for (int i = 1; i <= 7; ++i) cin >> pos[i].x >> pos[i].y;

		double p; cin >> p;

		vector<int> perm = { 1, 2, 3, 4, 5, 6, 7 };
		do {
			bool simple = true;
			for (int i = 0; i < 7; ++i) {
				pdd a = pos[perm[i]], b = pos[perm[(i + 1) % 7]];
				pdd ab = pdd(b.x - a.x, b.y - a.y);
				for (int j = 0; j < 7; ++j) {
					if (i == j) continue;
					pdd c = pos[perm[j]], d = pos[perm[(j + 1) % 7]];
					pdd ac = pdd(c.x - a.x, c.y - a.y);
					pdd ad = pdd(d.x - a.x, d.y - a.y);
					pdd cd = pdd(d.x - c.x, d.y - c.y);
					pdd ca = pdd(a.x - c.x, a.y - c.y);
					pdd cb = pdd(b.x - c.x, b.y - c.y);
					if (j == (i + 1) % 7) {
						if (accw(ab, ad) != 0) continue;
						if (a.x == b.x && (d.y - a.y) * (d.y - b.y) > 0) continue;
						else if ((d.x - a.x) * (d.x - b.x) > 0) continue;
						simple = false;
					}
					else if (i == (j + 1) % 7) {
						if (accw(ab, ac) != 0) continue;
						if (a.x == b.x && (c.y - a.y) * (c.y - b.y) > 0) continue;
						else if ((c.x - a.x) * (c.x - b.x) > 0) continue;
						simple = false;
					}
					else {
						if (accw(ab, ac) * accw(ab, ad) > 0) continue;
						if (accw(cd, ca) * accw(cd, cb) > 0) continue;
						simple = false;
					}
					if (!simple) break;
				}
				if (!simple) break;
			}
			if (!simple) continue;

			double area = 0;
			for (int i = 1; i < 6; ++i) {
				pdd a = pdd(pos[perm[i]].x - pos[perm[0]].x, pos[perm[i]].y - pos[perm[0]].y);
				pdd b = pdd(pos[perm[i + 1]].x - pos[perm[0]].x, pos[perm[i + 1]].y - pos[perm[0]].y);
				area += ccw(a, b) / 2;
			}
			area = abs(area) / 4.0;
			if (abs(pow(area, 3) - p) < 0.00001f) {
				for (int x : perm) cout << x << ' ';
				cout << '\n';
				break;
			}
		} while (next_permutation(perm.begin(), perm.end()));
	}
}