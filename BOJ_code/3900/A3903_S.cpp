// BOJ 3903 ¡¶¡÷µµ
// inradius of polygon

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using pdd = pair<double, double>;
#define x first
#define y second

double ccw(pdd a, pdd aa, pdd b, pdd bb) {
	double ret = (aa.x - a.x) * (bb.y - b.y) - (aa.y - a.y) * (bb.x - b.x);
	return ret;
}
double dist(pdd a, pdd b) {
	double ret = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
	return sqrt(ret);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n) {
		if (!n) break;

		vector<pdd> P(n);
		for (int i = 0; i < n; ++i) cin >> P[i].x >> P[i].y;

		double ans = 1e7;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				for (int k = j + 1; k < n; ++k) {
					bool par = false;
					int can[3] = { i, j, k };
					for (int l = 0; l < 3; ++l) {
						pdd a = P[can[l]], b = P[can[(l + 1) % 3]];
						pdd aa = P[(can[l] + 1) % n], bb = P[(can[(l + 1) % 3] + 1) % n];
						if (a.x == aa.x && b.x == bb.x) par = true;
						if (a.y == aa.y && b.y == bb.y) par = true;
						if ((a.x - aa.x) * (b.y - bb.y) == (a.y - aa.y) * (b.x - bb.x)) par = true;
						if (par) {
							int t3 = can[l], t1 = can[(l + 1) % 3], t2 = can[(l + 2) % 3];
							can[0] = t1; can[1] = t2; can[2] = t3;
							break;
						}
					}
					int cand[3] = { (can[0] + 1) % n, (can[1] + 1) % n, (can[2] + 1) % n };
					double radius = 1e7;
					if (!par) {
						if (ccw(P[can[0]], P[cand[0]], P[can[2]], P[cand[2]]) > 0) continue;
						if (ccw(P[can[1]], P[cand[1]], P[can[0]], P[cand[0]]) > 0) continue;
						if (ccw(P[can[2]], P[cand[2]], P[can[1]], P[cand[1]]) > 0) continue;

						double
							u1 = P[cand[0]].x - P[can[0]].x, v1 = P[cand[0]].y - P[can[0]].y,
							u2 = P[cand[1]].x - P[can[1]].x, v2 = P[cand[1]].y - P[can[1]].y,
							u3 = P[cand[2]].x - P[can[2]].x, v3 = P[cand[2]].y - P[can[2]].y;
						double
							p = (v1 * (P[can[1]].x - P[can[0]].x) - u1 * (P[can[1]].y - P[can[0]].y)) / (u1 * v2 - v1 * u2),
							q = (v3 * (P[can[1]].x - P[can[2]].x) - u3 * (P[can[1]].y - P[can[2]].y)) / (u3 * v2 - v3 * u2),
							r = (v3 * (P[can[0]].x - P[can[2]].x) - u3 * (P[can[0]].y - P[can[2]].y)) / (u3 * v1 - u1 * v3);
						pdd A = { P[can[1]].x + p * u2, P[can[1]].y + p * v2 },
							B = { P[can[1]].x + q * u2, P[can[1]].y + q * v2 },
							C = { P[can[0]].x + r * u1, P[can[0]].y + r * v1 };

						double S = abs(ccw(C, A, C, B));
						double L = dist(C, A) + dist(C, B) + dist(A, B);

						radius = S / L;
					}
					else {
						if (P[cand[0]].y == P[can[0]].y)
							radius = abs(P[can[2]].y - P[can[0]].y);
						else if (P[cand[0]].x == P[can[0]].x)
							radius = abs(P[can[2]].x - P[can[0]].x);
						else {
							double S = abs(ccw(P[can[0]], P[cand[0]], P[can[0]], P[cand[2]]));
							radius = S / dist(P[can[0]], P[cand[0]]);
						}
						radius /= 2;
					}
					ans = min(ans, radius);
				}
			}
		}
		cout << fixed;
		cout.precision(6);
		cout << ans << '\n';
	}
}