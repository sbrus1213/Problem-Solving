// BOJ 1108 검색 엔진
// SCC tarzan & topological sort

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
const int mxv = 2501;

vector<vector<int> > adj(mxv), scc, scc_adj(mxv);
vector<int> vis(mxv), st, scc_idx(mxv);
vector<ll> score(mxv, 1);
vector<bool> fin(mxv);
int dfsn, scc_sz;

int dfs(int cur) {
	st.push_back(cur);
	int low = vis[cur] = ++dfsn;
	for (int next : adj[cur]) {
		if (!vis[next]) low = min(low, dfs(next));
		else if (!fin[next]) low = min(low, vis[next]);
	}
	if (low == vis[cur]) {
		scc.resize(scc_sz + 1);
		while (!st.empty()) {
			int elem = st.back(); st.pop_back();
			scc[scc_sz].push_back(elem);
			scc_idx[elem] = scc_sz;
			fin[elem] = 1;
			if (elem == cur) break;
		}
		scc_sz++;
	}
	return low;
}
void scc_dfs(int cur) {
	vis[cur] = true;
	for (int next : scc_adj[cur])
		if (!vis[next])
			scc_dfs(next);
	st.push_back(cur);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int cnt = 1;
	map<string, int> dic;
	for (int i = 0; i < n; ++i) {
		int ind;
		string dest, src;
		cin >> dest >> ind;
		if (!dic[dest]) dic[dest] = cnt++;
		for (int j = 0; j < ind; ++j) {
			cin >> src;
			if (!dic[src]) dic[src] = cnt++;
			adj[dic[src]].push_back(dic[dest]);
		}
	}

	int v = dic.size();
	for (int i = 1; i <= v; ++i)
		if (!vis[i])
			dfs(i);

	for (int i = 1; i <= v; ++i)
		for (int j : adj[i])
			if (scc_idx[i] != scc_idx[j])
				scc_adj[scc_idx[i]].push_back(scc_idx[j]);

	fill(vis.begin(), vis.end(), 0);
	for (int i = 0; i < scc_sz; ++i)
		if (!vis[i])
			scc_dfs(i);

	while (!st.empty()) {
		int cur_idx = st.back(); st.pop_back();
		for (int cur : scc[cur_idx])
			for (int next : adj[cur])
				if (scc_idx[cur] != scc_idx[next])
					score[next] += score[cur];
	}

	string web;
	cin >> web;
	cout << score[dic[web]];
}