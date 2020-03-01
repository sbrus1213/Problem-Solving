// BOJ 11437 LCA
// LCA & Dynamic Programming

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj, parent;
vector<int> level;
vector<bool> visited;

void get_tree(int curr, int prev) {

	visited[curr] = true;
	level[curr] = level[prev] + 1;
	parent[curr][0] = prev;

	for (int i = 1; i < parent[curr].size(); ++i) {
		int par = parent[curr][i - 1];

		parent[curr][i] = parent[par][i - 1];
	}

	for (int next : adj[curr]) {
		if (!visited[next])
			get_tree(next, curr);
	}
}
void make_samelevel(int& curr, int to) {
	int up = 0, diff = level[curr] - level[to];
	while (diff) {
		if (diff % 2) {
			curr = parent[curr][up];
		}
		diff >>= 1; up++;
	}
}
int get_lac(int u, int v) {
	if (level[u] != level[v]) {
		if (level[u] > level[v]) make_samelevel(u, v);
		else make_samelevel(v, u);
	}

	if (u == v) return u;

	for (int i = parent[u].size() - 1; i >= 0; --i) {
		if (parent[u][i] != parent[v][i])
			u = parent[u][i], v = parent[v][i];
	}

	return parent[u][0];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;
	adj.resize(n + 1);
	parent.resize(n + 1, vector<int>(17));
	level.resize(n + 1, 0);
	visited.resize(n + 1);

	for (int i = 1; i < n; ++i) {
		int u, v;

		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	level[0] = -1;
	get_tree(1, 0);

	int m;

	cin >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;

		cin >> u >> v;

		cout << get_lac(u, v) << '\n';
	}
}