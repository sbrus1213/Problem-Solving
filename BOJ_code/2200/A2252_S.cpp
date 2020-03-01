// BOJ 2252 줄 세우기
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
	vector<int> indegree(n + 1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		indegree[b]++;
	}

	queue<int> Q;
	for (int i = 1; i <= n; ++i)
		if (!indegree[i])
			Q.push(i);

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		cout << cur << ' ';
		for (int next : adj[cur]) {
			indegree[next]--;
			if (!indegree[next]) Q.push(next);
		}
	}
}