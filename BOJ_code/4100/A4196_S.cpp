// BOJ 2150 Strongly Connected Component
// SCC Tarjan

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mxv = 100001;

vector<vector<int> > adj(mxv), SCC;
vector<int> vis(mxv), fin(mxv), ST, scc_idx(mxv), scc_ind(mxv);
int sz, dfsn;

int dfs(int cur) {
	vis[cur] = ++dfsn;
	ST.push_back(cur);

	int low = vis[cur];
	for (int next : adj[cur]) {
		if (!vis[next]) low = min(low, dfs(next));
		else if (!fin[next]) low = min(low, vis[next]);
	}
	if (low == vis[cur]) {
		SCC.push_back({});
		while (!ST.empty()) {
			int elem = ST.back();
			ST.pop_back();
			SCC[sz].push_back(elem);
			scc_idx[elem] = sz;
			fin[elem] = 1;
			if (elem == cur) break;
		}
		sz++;
	}
	return low;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		int v, e;
		cin >> v >> e;

		for (int i = 1; i <= v; ++i) adj[i] = {};

		for (int i = 0; i < e; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}

		sz = 0;
		SCC.clear();
		fill(fin.begin(), fin.end(), 0);
		fill(vis.begin(), vis.end(), 0);
		for (int i = 1; i <= v; ++i)
			if (!vis[i])
				dfs(i);

		fill(scc_ind.begin(), scc_ind.end(), 0);
		for (int i = 1; i <= v; ++i)
			for (int j : adj[i])
				if (scc_idx[i] != scc_idx[j])
					scc_ind[scc_idx[j]]++;

		int ans = 0;
		for (int i = 0; i < sz; ++i)
			if (!scc_ind[i])
				ans++;

		cout << ans << '\n';
	}
}