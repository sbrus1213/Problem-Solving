// BOJ 14942 °³¹Ì
// Sparse table

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int mxn = 100001;
const int psz = 15;

int n;
vector<vector<pii> > adj(mxn);
vector<int> par(mxn), dist(mxn);

void dfs(int cur, int prev, int d) {
	par[cur] = prev;
	dist[cur] = d;
	for (pii nxt : adj[cur]) {
		if (nxt.first == prev) continue;
		dfs(nxt.first, cur, nxt.second);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	vector<int> ene(n + 1);
	for (int i = 1; i <= n; ++i) cin >> ene[i];

	for (int i = 1; i < n; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	dfs(1, 0, 0);

	for (int i = 1; i <= n; ++i) {
		int en = ene[i], up = i;
		while (en >= dist[up] && up != 1) {
			en -= dist[up];
			up = par[up];
		}
		cout << up << '\n';
	}
}