// BOJ 1197 최소 스패닝 트리
// MST

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int u, v, w;
};

int par[10001];

int find(int i) {
	if (par[i] < 0) return i;
	return par[i] = find(par[i]);
}
bool merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return false;
	par[x] = y;
	return true;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int v, e; cin >> v >> e;

	vector<Edge> edge(e);
	for (auto& ee : edge) cin >> ee.u >> ee.v >> ee.w;
	sort(edge.begin(), edge.end(), [&](Edge a, Edge b) {
		return a.w < b.w;
		});

	long long ans = 0;
	fill(par, par + 10001, -1);
	for (auto& ee : edge)
		if (merge(ee.u, ee.v))
			ans += ee.w;

	cout << ans;
}