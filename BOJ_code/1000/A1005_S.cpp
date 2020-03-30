// BOJ 1005 ACM Craft
// Topological sort

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int n, m; cin >> n >> m;
		vector<vector<int> > adj(n + 1);
		vector<int> ind(n + 1), time(n + 1), res(n + 1);
		for (int i = 1; i <= n; ++i) cin >> time[i];
		for (int i = 0; i < m; ++i) {
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			ind[y]++;
		}
		int w; cin >> w;
		queue<int> Q;
		for (int i = 1; i <= n; ++i)
			if (!ind[i]) {
				Q.push(i);
				res[i] = time[i];
			}
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			for (int nxt : adj[cur]) {
				ind[nxt]--;
				res[nxt] = max(res[nxt], res[cur]);
				if (!ind[nxt]) {
					Q.push(nxt);
					res[nxt] += time[nxt];
					if (nxt == w) while (!Q.empty()) Q.pop();
				}
			}
		}
		cout << res[w] << '\n';
	}
}