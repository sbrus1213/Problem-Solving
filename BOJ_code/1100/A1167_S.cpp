// BOJ 1167 트리의 지름
// DFS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

vector<vector<pii> > adj;
vector<int> dist;

void dfs(int cur, int prv) {
	for (pii nxt : adj[cur]) {
		if (nxt.first == prv) continue;
		if (dist[nxt.first]) continue;
		dist[nxt.first] = dist[cur] + nxt.second;
		dfs(nxt.first, cur);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	adj = vector<vector<pii> >(n + 1);
	dist = vector<int>(n + 1);
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		int t, d;
		while (cin >> t) {
			if (t == -1) break;
			cin >> d;
			adj[x].push_back({ t, d });
		}
	}

	dist[1] = 1;
	dfs(1, 0);

	int idx = max_element(dist.begin(), dist.end()) - dist.begin();

	fill(dist.begin(), dist.end(), 0);
	dist[idx] = 1;
	dfs(idx, 0);

	cout << *max_element(dist.begin(), dist.end()) - 1;
}