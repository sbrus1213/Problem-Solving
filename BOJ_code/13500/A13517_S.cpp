// BOJ 13517 Æ®¸®¿Í Äõ¸® 8
// Persistent segment tree & LCA & Segment tree

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int lower = 0;
const int upper = 1e5;

struct pnode {
	int l, r, val;
	pnode() : pnode(0, 0, 0) {}
	pnode(int _l, int _r, int _v) :l(_l), r(_r), val(_v) {}
};

int n;

vector<pnode> pst(1);
vector<int> wgt, rt;
vector<ll> wlist;

void pst_init(vector<int>& val, int node = 1, int ns = 1, int ne = n) {
	if (ns == ne) {
		pst[node].val = val[ns];
		return;
	}
	int mid = (ns + ne) / 2;
	pst.push_back(pnode()); pst[node].l = pst.size() - 1;
	pst_init(val, pst[node].l, ns, mid);
	pst.push_back(pnode()); pst[node].r = pst.size() - 1;
	pst_init(val, pst[node].r, mid + 1, ne);
	pst[node].val = pst[pst[node].l].val + pst[pst[node].r].val;
}
void pst_update(int idx, int node, int ns = 1, int ne = n) {
	if (ns == ne) return;
	int mid = (ns + ne) / 2;
	if (idx <= mid) {
		int l = pst[node].l;
		pst.push_back(pnode(pst[l].l, pst[l].r, pst[l].val + 1));
		pst[node].l = pst.size() - 1;
		pst_update(idx, pst[node].l, ns, mid);
	}
	else {
		int r = pst[node].r;
		pst.push_back(pnode(pst[r].l, pst[r].r, pst[r].val + 1));
		pst[node].r = pst.size() - 1;
		pst_update(idx, pst[node].r, mid + 1, ne);
	}
}
void pst_new(int cur, int par) {
	int prv = rt[par];
	pst.push_back(pnode(pst[prv].l, pst[prv].r, pst[prv].val + 1));
	rt[cur] = pst.size() - 1;
	pst_update(wgt[cur], rt[cur]);
}
int pst_sum(int l, int r, int node, int ns = 1, int ne = n) {
	if (l <= ns && ne <= r) return pst[node].val;
	if (r < ns || ne < l) return 0;
	int mid = (ns + ne) / 2;
	return pst_sum(l, r, pst[node].l, ns, mid) + pst_sum(l, r, pst[node].r, mid + 1, ne);
}

vector<int> lev;
vector<vector<int>> adj, par;
void dfs(int cur, int prv) {
	lev[cur] = lev[prv] + 1;
	par[cur][0] = prv;
	pst_new(cur, prv);
	for (int nxt : adj[cur])
		if (nxt != prv)
			dfs(nxt, cur);
}
void mktable() {
	for (int i = 1; i <= 16; ++i)
		for (int j = 1; j <= n; ++j)
			par[j][i] = par[par[j][i - 1]][i - 1];
}
int lca(int u, int v) {
	if (lev[u] < lev[v]) swap(u, v);
	int diff = lev[u] - lev[v], x = 0;
	while (diff) {
		if (diff % 2) u = par[u][x];
		diff /= 2; x++;
	}
	if (u == v) return u;
	for (int i = 16; i >= 0; --i)
		if (par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	u = v = par[u][0];
	return u;
}

void solve(int u, int v, int k) {
	int w = lca(u, v);
	int pw = par[w][0];
	int low = 1, high = n;
	while (low < high) {
		int cnt = 0, mid = (low + high) / 2;
		cnt += pst_sum(1, mid, rt[u]);
		cnt += pst_sum(1, mid, rt[v]);
		cnt -= pst_sum(1, mid, rt[w]);
		cnt -= pst_sum(1, mid, rt[pw]);
		if (cnt >= k) high = mid;
		else low = mid + 1;
	}
	cout << wlist[high] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	wgt = vector<int>(n + 1);
	wlist = { -1LL << 40 };
	for (int i = 1; i <= n; ++i) {
		cin >> wgt[i];
		wlist.push_back(wgt[i]);
	}
	sort(wlist.begin(), wlist.end());
	for (int i = 1; i <= n; ++i) {
		wgt[i] = lower_bound(wlist.begin(), wlist.end(), wgt[i]) - wlist.begin();
	}

	adj = vector<vector<int>>(n + 1);
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	rt = vector<int>(n + 1);
	lev = vector<int>(n + 1);
	par = vector<vector<int>>(n + 1, vector<int>(17));
	dfs(1, 0);
	mktable();

	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		int u, v, k; cin >> u >> v >> k;
		solve(u, v, k);
	}
}