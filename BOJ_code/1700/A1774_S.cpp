// BOJ 1774 우주신과의 교감
// MST

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using pdd = pair<double, double>;
#define x first
#define y second

inline double dist(pdd a, pdd b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct Edge {
	int u, v;
	double d;
};

int par[1001];
int find(int i) {
	if (par[i] < 0) return i;
	return par[i] = find(par[i]);
}
bool merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return false;
	par[a] = b;
	return true;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vector<pdd> p(n);
	for (int i = 0; i < n; ++i)
		cin >> p[i].x >> p[i].y;

	fill(par, par + 1001, -1);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		merge(--u, --v);
	}

	vector<Edge> edge;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			edge.push_back({ i, j, dist(p[i], p[j]) });
	sort(edge.begin(), edge.end(), [&](Edge a, Edge b) {
		return a.d < b.d;
		});

	double ans = 0;
	for (auto& ee : edge)
		if (merge(ee.u, ee.v))
			ans += ee.d;

	cout << fixed;
	cout.precision(2);
	cout << ans;
}