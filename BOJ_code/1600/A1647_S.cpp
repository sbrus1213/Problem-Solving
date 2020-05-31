// BOJ 1647 도시 분할 계획
// MST

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int u, v, w;
};

vector<int> par;
int find(int i) {
	if (par[i] < 0) return i;
	return par[i] = find(par[i]);
}
bool merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return false;
	par[y] = x;
	return true;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vector<Edge> edge;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		edge.push_back({ u, v, w });
	}
	sort(edge.begin(), edge.end(), [&](Edge a, Edge b) {
		return a.w < b.w;
		});

	int sum = 0, mx = 0;
	par = vector<int>(n + 1, -1);
	for (auto& e : edge) {
		if (merge(e.u, e.v)) {
			sum += e.w;
			mx = max(mx, e.w);
		}
	}

	cout << sum - mx;
}