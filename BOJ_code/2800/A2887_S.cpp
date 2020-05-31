// BOJ 2887 행성 터널
// MST

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	int x, y, z, i;
};
struct Edge {
	int u, v, c;
};

vector<int> par;
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
	for (int i = 0; i < n; ++i) {
		cin >> p[i].x >> p[i].y >> p[i].z;
		p[i].i = i;
	}

	vector<Edge> edge;

	sort(p.begin(), p.end(), [&](Point a, Point b) {
		return a.x < b.x;
		});
	for (int i = 1; i < n; ++i)
		edge.push_back({ p[i - 1].i, p[i].i, p[i].x - p[i - 1].x });

	sort(p.begin(), p.end(), [&](Point a, Point b) {
		return a.y < b.y;
		});
	for (int i = 1; i < n; ++i)
		edge.push_back({ p[i - 1].i, p[i].i, p[i].y - p[i - 1].y });

	sort(p.begin(), p.end(), [&](Point a, Point b) {
		return a.z < b.z;
		});
	for (int i = 1; i < n; ++i)
		edge.push_back({ p[i - 1].i, p[i].i, p[i].z - p[i - 1].z });

	sort(edge.begin(), edge.end(), [&](Edge a, Edge b) {
		return a.c < b.c;
		});

	par = vector<int>(n, -1);
	long long ans = 0;
	for (auto& ee : edge)
		if (merge(ee.u, ee.v))
			ans += ee.c;

	cout << ans;
}