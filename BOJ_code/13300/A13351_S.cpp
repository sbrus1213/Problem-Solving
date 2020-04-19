// BOJ 13351 Rock Band
// DFS BFS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;
vector<bool> vis;

void dfs(int cur) {
	vis[cur] = true;
	for (int nxt : adj[cur])
		if (!vis[nxt])
			dfs(nxt);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	adj = vector<vector<int> >(m + 1);
	vis = vector<bool>(m + 1);
	vector<int> must(n);
	for (int i = 0; i < n; ++i) {
		int p; cin >> p;
		must[i] = p;
		for (int i = 1; i < m; ++i) {
			int x; cin >> x;
			adj[x].push_back(p);
			p = x;
		}
	}

	for (int i = 0; i < n; ++i)
		if (!vis[must[i]])
			dfs(must[i]);

	vector<int> ans;
	for (int i = 1; i <= m; ++i)
		if (vis[i]) ans.push_back(i);

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int x : ans) cout << x << ' ';
}