// BOJ 17398 ≈ÎΩ≈∏¡ ∫–«“
// Offline query & union find

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct edge {
	int u, v;
	bool cut;
};

vector<ll> par;
vector<edge> E;

int find(int x) {
	if (par[x] < 0) return x;
	return par[x] = find(par[x]);
}
ll merge(int x, int y) {
	int px = find(x), py = find(y);
	if (px == py) return 0;
	ll ret = par[px] * par[py];
	par[px] += par[py];
	par[py] = px;
	return ret;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;

	par = vector<ll>(n + 1, -1);
	E = vector<edge>(m + 1);
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		E[i] = { u, v, false };
	}

	vector<int> cut(k);
	for (int i = k - 1; i >= 0; --i) {
		cin >> cut[i];
		E[cut[i]].cut = true;
	}

	for (int i = 1; i <= m; ++i)
		if (!E[i].cut) merge(E[i].u, E[i].v);

	ll ans = 0;
	for (int i = 0; i < k; ++i)
		ans += merge(E[cut[i]].u, E[cut[i]].v);

	cout << ans;
}