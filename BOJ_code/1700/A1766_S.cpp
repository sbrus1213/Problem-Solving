// BOJ 1766 ¹®Á¦Áý
// Topological sort

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 1; i <= n; ++i)
		if (!ind[i]) pq.push(i);

	while (!pq.empty()) {
		int cur = pq.top(); pq.pop();
		cout << cur << ' ';
		for (int next : adj[cur]) {
			ind[next]--;
			if (!ind[next]) pq.push(next);
		}
	}
}