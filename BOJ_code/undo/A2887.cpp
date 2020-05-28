// BOJ 2887 행성 터널
// MST

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
	int x, y, z;
};
struct Edge {
	int u, v, c;
};

int par[100001];
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

	int n; cin >> n;

	vector<Point> p(n);
	for (auto& pp : p)
		cin >> pp.x >> pp.y >> pp.z;

	fill(par, par + 100001, -1);

	vector<Edge> edge;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			edge.push_back({ i, j, min({abs(p[i].x - p[j].x), abs(p[i].y - p[j].y), abs(p[i].z - p[j].z)}) });
	sort(edge.begin(), edge.end(), [&](Edge a, Edge b) {
		return a.c < b.c;
		});

	long long ans = 0;
	for (auto& ee : edge)
		if (merge(ee.u, ee.v))
			ans += ee.c;

	cout << ans;
}