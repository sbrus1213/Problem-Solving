// BOJ 16074 Mountaineers
// MST & LCA

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <set>
#include <tuple>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
#define ll	long long
#define BtoE(vec) vec.begin(), vec.end()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Psi pair<string, int>
#define Tii tuple<int, int, int>

struct edge {
	int w, s, e;
};

int n, m, q;
vector<vector<int> > adj;
vector<vector<Pii > > par;
vector<int> mountain, uf, level;
vector<bool> vis;
Pii from[501], to[501];
vector<edge> E;

bool comp(edge a, edge b) {
	if (a.w < b.w) return true;
	else return false;
}

int find(int i) {
	if (uf[i] == -1) return i;
	return uf[i] = find(uf[i]);
}
bool merging(int i, int j) {
	i = find(i), j = find(j);

	if (i == j) return false;

	uf[i] += uf[j];
	uf[j] = i;
	return true;
}

void get_tree(int curr, int prev) {
	vis[curr] = true;
	level[curr] = level[prev] + 1;
	par[curr][0].first = prev;
	par[curr][0].second = 

	for (int i = 1; i < par[curr].size(); ++i) {
		int p = par[curr][i - 1];

		par[curr][i] = par[p][i - 1];
	}

	for (int next : adj[curr]) {
		if (!vis[next])
			get_tree(next, curr);
	}
}
void make_samelevel(int& curr, int to) {
	int up = 0, diff = level[curr] - level[to];
	while (diff) {
		if (diff % 2) {
			curr = par[curr][up];
		}
		diff >>= 1; up++;
	}
}
int get_lac(int u, int v) {
	if (level[u] != level[v]) {
		if (level[u] > level[v]) make_samelevel(u, v);
		else make_samelevel(v, u);
	}

	if (u == v) return u;

	for (int i = par[u].size() - 1; i >= 0; --i) {
		if (par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	}

	return par[u][0];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	cin >> n>>m>>q;
	mountain.resize(n * m + 1);
	uf.resize(n * m + 1);
	adj.resize(n * m + 1);
	par.resize(n * m + 1, vector<int>(16));
	level.resize(n * m + 1);
	vis.resize(n * m + 1);

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> mountain[i * m + j + 1];

	for (int i = 0; i < q; ++i) cin >> from[i].first >> from[i].second >> to[i].first >> to[i].second;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i != n-1) E.push_back({ max(mountain[i * m + j + 1], mountain[(i + 1) * m + j + 1]), i * m + j + 1, (i + 1) * m + j + 1 });
			if (j != m -1) E.push_back({ max(mountain[i * m + j + 1], mountain[i * m + j + 2]), i* m + j + 1, i * m + j + 2 });			
		}
	}
	sort(BtoE(E), comp);

	int len = E.size();
	fill(BtoE(uf), -1);
	for (int i = 0; i < len; ++i) {
		int u = E[i].s, v = E[i].e;
		if (merging(u, v)) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	
	fill(BtoE(vis), false);
	fill(BtoE(par), -1);
	get_tree(1, 0);

	for (int i = 0; i < q; ++i) {

	}
}