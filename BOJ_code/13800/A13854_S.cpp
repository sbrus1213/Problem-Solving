// BOJ 13854 트리와 소수
// centroid decomposition & tree dp & linear programming

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
using ll = long long;
using ld = long double;
const int mxn = 50'005;

vector<vector<int>> adj;
vector<int> sz, prime, tmp;
vector<ll> sub;
bitset<mxn> vis;

int get_sz(int cur, int prv = -1) {
	sz[cur] = 1;
	for (int nxt : adj[cur]) {
		if (nxt == prv || vis[nxt]) continue;
		sz[cur] += get_sz(nxt, cur);
	}
	return sz[cur];
}
int get_cen(int half, int cur, int prv = -1) {
	for (int nxt : adj[cur]) {
		if (nxt == prv || vis[nxt]) continue;
		if (sz[nxt] > half)
			return get_cen(half, nxt, cur);
	}
	return cur;
}

int id;
ll find(int dep, int cur, int prv = -1) {
	if (dep > prime[id]) return 0;
	ll ret = 0;
	for (int i = id; i >= 0; --i) {
		if (prime[i] >= dep) ret += sub[prime[i] - dep];
		else break;
	}
	for (int nxt : adj[cur]) {
		if (nxt == prv || vis[nxt]) continue;
		ret += find(dep + 1, nxt, cur);
	}
	return ret;
}
void update(int dep, int cur, int prv = -1) {
	if (dep > prime[id]) return;
	tmp.push_back(dep);
	sub[dep]++;
	for (int nxt : adj[cur]) {
		if (nxt == prv || vis[nxt]) continue;
		update(dep + 1, nxt, cur);
	}
}

ll solve(int cur) {
	ll ret = 0;
	int siz = get_sz(cur);
	int cen = get_cen(siz / 2, cur);
	vis[cen] = 1;

	int mx = sz[cur] - 1;
	id = lower_bound(prime.begin(), prime.end(), mx) - prime.begin();
	id = min(id, (int)prime.size() - 1);

	while (!tmp.empty()) sub[tmp.back()] = 0, tmp.pop_back();
	sub[0] = 1;
	for (int nxt : adj[cen]) {
		if (vis[nxt]) continue;
		ret += find(1, nxt);
		update(1, nxt);
	}

	for (int nxt : adj[cen]) {
		if (vis[nxt]) continue;
		ret += solve(nxt);
	}

	return ret;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	adj = vector<vector<int>>(n);
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 2; i < n; ++i) {
		bool p = true;
		for (int j = 2; j * j <= i; ++j)
			if (!(i % j)) {
				p = false;
				break;
			}
		if (p) prime.push_back(i);
	}

	sz = vector<int>(n);
	sub = vector<ll>(n);
	ll res = solve(0);
	ld ans = (ld)res * 2;
	ans /= (ld)n * (n - 1);
	cout << fixed;
	cout.precision(6);
	cout << ans;
}