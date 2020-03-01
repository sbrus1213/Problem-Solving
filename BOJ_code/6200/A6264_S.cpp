// BOJ 6264 Sub-dictionary
// SCC tarzan & topological sort

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
const int mxv = 101;

vector<vector<int> > adj(mxv), scc, scc_prev(mxv), scc_adj(mxv);
vector<int> vis(mxv), st, scc_idx(mxv), scc_ind(mxv);
vector<bool> fin(mxv), scc_need(mxv);
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

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		fill(adj.begin(), adj.end(), vector<int>());
		scc.clear();

		int n;
		cin >> n;
		if (!n) break;
		cin.ignore(2, '\n');

		int cnt = 1;
		map<string, int> dic;
		map<int, string> dic2;
		for (int i = 0; i < n; ++i) {
			bool flag = true;
			string dest, src, str;
			getline(cin, str);
			for (int i = 0; i < str.size(); ++i) {
				if (str[i] == ' ') {
					if (flag) {
						flag = false;
						if (!dic[dest]) {
							dic[dest] = cnt;
							dic2[cnt++] = dest;
						}
					}
					else {
						if (!dic[src]) {
							dic[src] = cnt;
							dic2[cnt++] = src;
						}
						adj[dic[src]].push_back(dic[dest]);
						src = "";
					}
				}
				else {
					if (flag) dest.push_back(str[i]);
					else src.push_back(str[i]);
				}
			}

			if (!dic[src]) {
				dic[src] = cnt;
				dic2[cnt++] = src;
			}
			adj[dic[src]].push_back(dic[dest]);
		}

		fill(vis.begin(), vis.end(), 0);
		fill(fin.begin(), fin.end(), false);
		dfsn = scc_sz = 0;
		for (int i = 1; i <= n; ++i)
			if (!vis[i])
				dfs(i);

		fill(scc_ind.begin(), scc_ind.end(), 0);
		fill(scc_adj.begin(), scc_adj.end(), vector<int>());
		fill(scc_prev.begin(), scc_prev.end(), vector<int>());
		for (int i = 1; i <= n; ++i)
			for (int j : adj[i])
				if (scc_idx[i] != scc_idx[j]) {
					scc_ind[scc_idx[j]]++;
					scc_adj[scc_idx[i]].push_back(scc_idx[j]);
					scc_prev[scc_idx[j]].push_back(scc_idx[i]);
				}

		fill(scc_need.begin(), scc_need.end(), false);
		queue<int> Q;
		for (int i = 0; i < scc_sz; ++i)
			if (!scc_ind[i]) {
				scc_need[i] = true;
				Q.push(i);
			}

		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			st.push_back(cur);
			if (scc[cur].size() > 1) scc_need[cur] = true;
			for (int next : scc_adj[cur]) {
				scc_ind[next]--;
				if (!scc_ind[next])
					Q.push(next);
			}
		}

		while (!st.empty()) {
			int cur = st.back(); st.pop_back();
			if (scc_need[cur])
				for (int prev : scc_prev[cur])
					scc_need[prev] = true;
		}

		vector<string> ans;
		for (int i = 0; i < scc_sz; ++i)
			if (scc_need[i])
				for (int j : scc[i])
					ans.push_back(dic2[j]);

		cout << ans.size() << '\n';
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
		cout << '\n';
	}
}