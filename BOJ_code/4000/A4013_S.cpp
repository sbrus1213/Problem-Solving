// BOJ 4013 ATM
// SCC Tarjan & topological sort

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int mxv = 500001;

vector<vector<int> > adj(mxv), scc_adj(mxv);
vector<int> vis(mxv), fin(mxv), atm(mxv), ST, scc_idx(mxv), scc_atm(mxv), scc_ind(mxv), scc_dp(mxv);
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
		while (!ST.empty()) {
			int elem = ST.back();
			ST.pop_back();
			scc_idx[elem] = sz;
			scc_atm[sz] += atm[elem];
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

	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= v; ++i) cin >> atm[i];

	int s, p;
	cin >> s >> p;

	vector<int> rest(p);
	for (int i = 0; i < p; ++i) cin >> rest[i];

	for (int i = 1; i <= v; ++i)
		if (!vis[i])
			dfs(i);

	for (int i = 1; i <= v; ++i)
		for (int j : adj[i])
			if (scc_idx[i] != scc_idx[j])
				scc_adj[scc_idx[i]].push_back(scc_idx[j]);

	fill(vis.begin(), vis.end(), 0);
	s = scc_idx[s];
	scc_dfs(s);

	queue<int> Q;
	Q.push(s);
	scc_dp[s] = scc_atm[s];
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int next : scc_adj[cur]) {
			scc_dp[next] = max(scc_dp[next], scc_dp[cur] + scc_atm[next]);
			--scc_ind[next];
			if (!scc_ind[next])
				Q.push(next);
		}
	}

	int ans = 0;
	for (int i = 0; i < p; ++i)
		ans = max(ans, scc_dp[scc_idx[rest[i]]]);
	cout << ans;
}