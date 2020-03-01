// BOJ 1389 케빈 베이컨의 6단계 법칙
// BFS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;
vector<int> dist;
vector<bool> visi;

void bfs(int s) {
	queue<int> Q;
	Q.push(s);
	dist[s] = 0;
	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();
		for (int next : adj[curr]) {
			if (visi[next]) continue;
			dist[next] = dist[curr] + 1;
			visi[next] = true;
			Q.push(next);
		}
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	dist.resize(n + 1);
	visi.resize(n + 1);
	adj.resize(n + 1);

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = 50000000, idx;
	for (int i = 1; i <= n; ++i) {
		fill(dist.begin(), dist.end(), 0);
		fill(visi.begin(), visi.end(), 0);

		visi[i] = true;
		bfs(i);

		int res = 0;
		for (int j = 1; j <= n; ++j) res += dist[j];
		if (ans > res) {
			ans = res;
			idx = i;
		}
	}
	cout << idx;
}