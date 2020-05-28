// BOJ 1033 칵테일
// DFS BFS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

struct Edge {
	int v, up, down;
};

vector<vector<Edge>> adj;
vector<pii> node;
vector<bool> vis;

void dfs(int cur, int prv) {
	vis[cur] = 1;
	for (auto& nxt : adj[cur]) {
		if (nxt.v == prv) continue;
		if (vis[nxt.v]) continue;
		vis[nxt.v] = 1;
		node[nxt.v] = pii(node[cur].first * nxt.down, node[cur].second * nxt.up);
		dfs(nxt.v, cur);
	}
}
ll gcd(ll a, ll b) {
	if (a > b) swap(a, b);
	while (a) {
		b %= a;
		swap(a, b);
	}
	return b;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	adj = vector<vector<Edge>>(n);
	for (int i = 1; i < n; ++i) {
		int a, b, p, q; cin >> a >> b >> p >> q;
		adj[a].push_back({ b, p, q });
		adj[b].push_back({ a, q, p });
	}

	vis = vector<bool>(n);
	node = vector<pii>(n);
	node[0] = { 1, 1 };
	dfs(0, 0);

	ll mul = node[0].second;
	for (int i = 1; i < n; ++i) {
		ll g = gcd(node[i].second, mul);
		mul *= node[i].second / g;
	}
	for (int i = 0; i < n; ++i) node[i].first *= (mul / node[i].second);

	ll g = node[0].first;
	for (int i = 1; i < n; ++i) g = gcd(g, node[i].first);

	for (int i = 0; i < n; ++i) cout << node[i].first / g << ' ';
}