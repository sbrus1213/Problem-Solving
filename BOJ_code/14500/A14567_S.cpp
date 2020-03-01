// BOJ 14567 선수과목 (Prerequisite)
// Topological sort

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > adj(n + 1);
	vector<int> ind(n + 1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		ind[b]++;
	}

	queue<pii > Q;
	for (int i = 1; i <= n; ++i)
		if (!ind[i])
			Q.push(pii(i, 1));

	vector<int> ans(n + 1);
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		ans[cur.first] = cur.second;
		for (int next : adj[cur.first]) {
			ind[next]--;
			if (!ind[next])
				Q.push(pii(next, cur.second + 1));
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
}