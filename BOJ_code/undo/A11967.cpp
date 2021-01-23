// BOJ 11967 ºÒÄÑ±â
// bfs & dfs

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> light[101][101];
bool on[101][101], vis[101][101];
int di[] = { 1, 0,-1, 0 }, dj[] = { 0, 1, 0, -1 };

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int x, y, a, b; cin >> x >> y >> a >> b;
		x--; y--; a--; b--;
		light[x][y].push_back(a*n + b);
	}

	on[0][0] = vis[0][0] = true;
	queue<int> q;
	for (int nxt : light[0][0]) {
		int i = nxt / n, j = nxt % n;
		on[i][j] = 1;
		q.push(i * n + j);
	}
	while (!q.empty()) {
		int sz = q.size();
		for (int t = 0; t < sz; ++t) {
			int cur = q.front(); q.pop();
			int i = cur / n, j = cur % n;
			if (vis[i][j]) continue;
			bool cango = false;
			for (int k = 0; k < 4; ++k) {
				int ni = i + di[k], nj = j + dj[k];
				if (ni < 0 || ni >= n) continue;
				if (nj < 0 || nj >= n) continue;
				if (vis[ni][nj]) cango = true;
			}
			if (!cango) continue;
			vis[i][j] = true;
			for (int nxt : light[i][j]) {
				int ni = nxt / n, nj = nxt % n;
				on[ni][nj] = true;
				q.push(ni * n + nj);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ans += on[i][j];

	cout << ans;
}