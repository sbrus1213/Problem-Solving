// BOJ 2152 여행 계획 세우기
// SCC Tarjan & topological sort

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int mxv = 10001;

vector<vector<int> > adj(mxv), SCC, scc_adj(mxv);
vector<int> vis(mxv), fin(mxv), ST, scc_idx(mxv), scc_ind(mxv), scc_dp(mxv);
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
void scc_dfs(int cur) {
	vis[cur] = 1;
	for (int next : scc_adj[cur]) {
		scc_ind[next]++;
		if (vis[next]) continue;
		scc_dfs(next);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int v, e, s, t;
	cin >> v >> e >> s >> t;

	for (int i = 0; i < e; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	for (int i = 1; i <= v; ++i)
		if (!vis[i])
			dfs(i);

	for (int i = 1; i <= v; ++i)
		for (int j : adj[i])
			if (scc_idx[i] != scc_idx[j])
				scc_adj[scc_idx[i]].push_back(scc_idx[j]);

	fill(vis.begin(), vis.end(), 0);
	s = scc_idx[s], t = scc_idx[t];
	scc_dfs(s);

	queue<int> Q;
	Q.push(s);
	scc_dp[s] = SCC[s].size();
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int next : scc_adj[cur]) {
			scc_dp[next] = max(scc_dp[next], scc_dp[cur] + (int)SCC[next].size());
			--scc_ind[next];
			if (!scc_ind[next])
				Q.push(next);
		}
	}
	cout << scc_dp[t];
}