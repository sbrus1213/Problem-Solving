// BOJ 1506 경찰서
// union fin & floyd warshall

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> par;

int find(int i) {
	if (par[i] < 0) return i;
	return par[i] = find(par[i]);
}
bool merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return false;
	par[x] = y;
	return true;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> cost(n + 1);
	for (int i = 1; i <= n; ++i) cin >> cost[i];

	int adj[101][101];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			char c; cin >> c;
			adj[i][j] = c - '0';
		}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				adj[i][j] |= adj[i][k] && adj[k][j];

	par = vector<int>(n + 1);
	for (int i = 1; i <= n; ++i) par[i] = -i;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (adj[i][j] && adj[j][i]) {
				merge(i, j);
			}
		}
	}

	vector<int> res(n + 1, 2e6);
	for (int i = 1; i <= n; ++i) {
		int p = find(i);
		res[p] = min(res[p], cost[i]);
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (res[i] != 2e6) ans += res[i];
	cout << ans;
}