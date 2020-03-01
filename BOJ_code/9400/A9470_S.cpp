// BOJ 9470 Strahler ¼ø¼­
// Topological sort

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		int k, m, p;
		cin >> k >> m >> p;

		vector<vector<int> > adj(m + 1), prev(m + 1);
		vector<int> ind(m + 1);
		for (int i = 0; i < p; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			prev[v].push_back(u);
			ind[v]++;
		}

		vector<int> strahler(m + 1);
		queue<int> Q;
		for (int i = 1; i <= m; ++i)
			if (!ind[i])
				Q.push(i);

		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			int mx = -1, cnt = 0;
			for (int pre : prev[cur]) {
				if (strahler[pre] > mx) {
					mx = strahler[pre];
					cnt = 1;
				}
				else if (strahler[pre] == mx)
					cnt++;
			}
			strahler[cur] = (!cnt ? 1 : cnt == 1 ? mx : mx + 1);
			for (int next : adj[cur]) {
				ind[next]--;
				if (!ind[next]) Q.push(next);
			}
		}

		int ans = -1;
		for (int i = 1; i <= m; ++i) ans = max(ans, strahler[i]);

		cout << k << ' ' << ans << '\n';
	}
}