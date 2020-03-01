// BOJ 17938 ≈ÎΩ≈∏¡ ∫–«“
// Offline Query & Union find

#include <iostream>
#include <vector>
using namespace std;
#define ll	long long

struct E {
	int x, y;
};
vector<int> par;

int find(int x) {
	if (par[x] < 0) return x;
	return par[x] = find(par[x]);
}
void merge(int x, int y) {
	int px = find(x), py = find(y);

	if (px == py) return;

	par[px] += par[py];
	par[py] = px;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, q;

	cin >> n >> m >> q;
	par.resize(n + 1, -1);

	vector<E> edge(m);
	for (int i = 0; i < m; ++i) {
		cin >> edge[i].x >> edge[i].y;
	}

	vector<bool> cut(m, false);
	vector<int> query(q);
	for (int i = 0; i < q; ++i) {
		cin >> query[i];

		cut[query[i] - 1] = true;
	}

	for (int i = 0; i < m; ++i) {
		if (!cut[i]) merge(edge[i].x, edge[i].y);
	}

	ll res = 0;
	for (int i = q - 1; i >= 0; --i) {
		int px = find(edge[query[i] - 1].x), py = find(edge[query[i] - 1].y);

		if (px == py) continue;

		res += (ll)par[px] * par[py];
		merge(px, py);
	}

	cout << res;
}