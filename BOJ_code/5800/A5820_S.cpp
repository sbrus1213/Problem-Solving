// BOJ 5820 ∞Ê¡÷
// centroid decomposition & tree dp & linear programming

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int mxn = 200'005;

vector<vector<pii>> adj;
vector<int> sz, mn, tmp;
bitset<mxn> vis;

int get_sz(int cur, int prv = -1) {
	sz[cur] = 1;
	for (auto nxt : adj[cur]) {
		if (nxt.first == prv || vis[nxt.first]) continue;
		sz[cur] += get_sz(nxt.first, cur);
	}
	return sz[cur];
}
int get_centroid(int half, int cur, int prv = -1) {
	for (auto nxt : adj[cur]) {
		if (nxt.first == prv || vis[nxt.first]) continue;
		if (sz[nxt.first] > half)
			return get_centroid(half, nxt.first, cur);
	}
	return cur;
}

int find(int cur, int prv, int k, int dist, int cnt) {
	int ret = mxn;
	if (k < dist) return ret;
	if (mn[k - dist] != mxn)
		ret = min(ret, mn[k - dist] + cnt);
	for (auto nxt : adj[cur]) {
		if (nxt.first == prv || vis[nxt.first]) continue;
		ret = min(ret, find(nxt.first, cur, k, dist + nxt.second, cnt + 1));
	}
	return ret;
}
void update(int cur, int prv, int k, int dist, int cnt) {
	if (k < dist) return;
	for (auto nxt : adj[cur]) {
		if (nxt.first == prv || vis[nxt.first]) continue;
		update(nxt.first, cur, k, dist + nxt.second, cnt + 1);
	}
	mn[dist] = min(cnt, mn[dist]);
	tmp.push_back(dist);
	return;
}

int solve(int cur, int k) {
	int ret = mxn;
	int size = get_sz(cur);
	int cen = get_centroid(size / 2, cur);
	vis[cen] = 1;

	for (auto& nxt : adj[cen]) {
		if (vis[nxt.first]) continue;
		ret = min(ret, solve(nxt.first, k));
	}

	while (!tmp.empty()) mn[tmp.back()] = mxn, tmp.pop_back();
	mn[0] = 0;
	for (auto& nxt : adj[cen])
		if (!vis[nxt.first]) {
			ret = min(ret, find(nxt.first, cen, k, nxt.second, 1));
			update(nxt.first, cen, k, nxt.second, 1);
		}

	vis[cen] = 0;
	return ret;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int v, k; cin >> v >> k;

	adj = vector<vector<pii>>(v);
	for (int i = 1; i < v; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	sz = vector<int>(v);
	mn = vector<int>(k + 1, mxn);
	int res = solve(0, k);
	cout << (res == mxn ? -1 : res);
}