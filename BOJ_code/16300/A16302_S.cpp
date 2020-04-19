// BOJ 16302 Jurassic Jigsaw
// MST

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct edge {
	int u, v, w;
};

vector<int> par;
int find(int x) {
	if (par[x] < 0) return x;
	return par[x] = find(par[x]);
}
bool merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return false;
	par[x] = y;
	return true;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, l; cin >> n >> l;

	vector<string> vs(n);
	for (int i = 0; i < n; ++i) cin >> vs[i];

	vector<edge> E;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			edge e = { i, j, 0 };
			for (int k = 0; k < l; ++k)
				if (vs[i][k] != vs[j][k]) e.w++;
			E.push_back(e);
		}
	}
	sort(E.begin(), E.end(), [&](edge a, edge b) {
		return a.w < b.w;
		});

	par = vector<int>(n, -1);
	vector<edge> mst;
	int ans = 0;
	for (auto& e : E) {
		if (merge(e.u, e.v)) {
			mst.push_back({ e.u, e.v, 0 });
			ans += e.w;
		}
	}

	cout << ans << '\n';
	for (auto& e : mst) cout << e.u << ' ' << e.v << '\n';
}