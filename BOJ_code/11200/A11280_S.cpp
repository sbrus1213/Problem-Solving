// BOJ 11280 2-SAT-3
// SCC

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const int MXV = 20001;

inline int idx(int x) {
	return x > 0 ? 2 * x - 1 : 2 * (-x);
}

vector<vector<int> > adj(MXV);
vector<int> dfsn(MXV), scc_idx(MXV);
vector<bool> fin(MXV);
stack<int> ST;
int cnt, scc_sz;

int dfs(int cur) {
	int low = dfsn[cur] = ++cnt;
	ST.push(cur);

	for (int next : adj[cur]) {
		if (!dfsn[next]) low = min(low, dfs(next));
		else if (!fin[next]) low = min(low, dfsn[next]);
	}

	if (low == dfsn[cur]) {
		while (1) {
			int elem = ST.top(); ST.pop();
			scc_idx[elem] = scc_sz;
			fin[elem] = true;
			if (elem == cur) break;
		}
		scc_sz++;
	}

	return low;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int p, q;
		cin >> p >> q;
		adj[idx(-p)].push_back(idx(q));
		adj[idx(-q)].push_back(idx(p));
	}

	for (int i = 1; i <= 2 * n; ++i)
		if (!dfsn[i])
			dfs(i);

	int ans = 1;
	for (int i = 1; i <= 2 * n; i += 2)
		if (scc_idx[i] == scc_idx[i + 1]) {
			ans = 0;
			break;
		}
	cout << ans;
}