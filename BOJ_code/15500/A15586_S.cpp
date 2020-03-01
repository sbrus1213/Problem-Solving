// BOJ 15586 Mootube (Gold)
// Offline query & union find

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	int u, v, w;
};
struct query {
	int k, v, idx, res;
};

vector<int> par;
vector<edge> E;

int find(int x) {
	if (par[x] < 0) return x;
	return par[x] = find(par[x]);
}
void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	par[x] += par[y];
	par[y] = x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;

	par = vector<int>(n + 1, -1);
	E = vector<edge>(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w; cin >> u >> v >> w;
		E[i] = { u, v, w };
	}
	sort(E.begin(), E.end(), [&](edge a, edge b) {
		return a.w > b.w;
		});

	vector<query> Q;
	for (int i = 0; i < q; ++i) {
		int k, v; cin >> k >> v;
		Q.push_back({ k, v, i, 0 });
	}
	sort(Q.begin(), Q.end(), [&](query a, query b) {
		return a.k > b.k;
		});

	for (int i = 0, j = 0; i < q; ++i) {
		int k = Q[i].k;
		while (j < n - 1 && E[j].w >= k) {
			merge(E[j].u, E[j].v);
			++j;
		}
		Q[i].res = -par[find(Q[i].v)] - 1;
	}

	sort(Q.begin(), Q.end(), [&](query a, query b) {
		return a.idx < b.idx;
		});
	for (int i = 0; i < q; ++i) cout << Q[i].res << '\n';
}