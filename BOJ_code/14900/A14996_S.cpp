// BOJ 14996 Intelligence Infection
// SCC & dfs

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	int u, v;
};
struct scc {
	vector<vector<int> > adj;
	vector<int> dfsn, fin, ST, scc_num, scc_ind, scc_res;
	int v, sz, cnt;
	scc(vector<vector<int>>& adj_) :adj(move(adj_)) {
		v = adj.size();
		dfsn = vector<int>(v);
		fin = vector<int>(v);
		scc_num = vector<int>(v);
		sz = cnt = 0;

		for (int i = 0; i < v; ++i)
			if (!dfsn[i])
				dfs(i);

		scc_ind = vector<int>(sz);
		scc_res = vector<int>(sz);
	}
	int dfs(int cur) {
		dfsn[cur] = ++cnt;
		ST.push_back(cur);

		int low = dfsn[cur];
		for (int next : adj[cur]) {
			if (!dfsn[next]) low = min(low, dfs(next));
			else if (!fin[next]) low = min(low, dfsn[next]);
		}
		if (low == dfsn[cur]) {
			while (!ST.empty()) {
				int elem = ST.back(); ST.pop_back();
				scc_num[elem] = sz;
				fin[elem] = 1;
				if (elem == cur) break;
			}
			sz++;
		}
		return low;
	}
	int dfs2(int cur, vector<bool>& ene) {
		int cc = scc_num[cur];
		dfsn[cur] = 1;
		scc_res[cc] = max(scc_res[cc], ene[cur] + 1);
		for (int nxt : adj[cur]) {
			if (dfsn[nxt]) {
				scc_res[cc] = max(scc_res[cc], scc_res[scc_num[nxt]]);
				continue;
			}
			scc_res[cc] = max(scc_res[cc], dfs2(nxt, ene));
		}
		return scc_res[cc];
	}
	void solve(int e, vector < bool>& ene) {
		dfsn = vector<int>(v);
		for (int i = 0; i < v; ++i)
			if (!dfsn[i])
				dfs2(i, ene);

		for (int i = 0; i < v; ++i) {
			if (scc_res[scc_num[i]] == 1) {
				for (int nxt : adj[i]) {
					if (scc_num[i] == scc_num[nxt]) continue;
					scc_ind[scc_num[nxt]]++;
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < v; ++i)
			if (!ene[i] && scc_res[scc_num[i]] == 2) ans++;
		for (int i = 0; i < sz; ++i)
			if (!scc_ind[i] && scc_res[i] == 1) ans++;
		cout << ans;
	}
};

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int s, e, c; cin >> s >> e >> c;

	vector<vector<int>> adj(s);
	for (int i = 0; i < c; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<bool> enemy(s);
	for (int i = 0; i < e; ++i) {
		int x; cin >> x;
		enemy[x] = 1;
	}

	scc S(adj);
	S.solve(e, enemy);
}