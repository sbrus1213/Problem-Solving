// BOJ 2638 치즈
// dfs bfs

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	int map[101][101];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> map[i][j];

	int ans = 0, dr[] = { 0 ,1, 0, -1 }, dc[] = { 1, 0, -1, 0 };
	for (ans = 0;; ans++) {
		bool chz = false;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				chz |= map[i][j];
		if (!chz) break;

		int vis[101][101] = {};
		vis[1][1] = 1;
		queue<pii> q;
		q.push({ 1, 1 });
		while (!q.empty()) {
			auto tmp = q.front(); q.pop();
			int r = tmp.first, c = tmp.second;
			for (int k = 0; k < 4; ++k) {
				int nr = r + dr[k], nc = c + dc[k];
				if (nr < 1 || nr > n) continue;
				if (nc < 1 || nc > m) continue;
				if (vis[nr][nc] || map[nr][nc] == 1) continue;
				vis[nr][nc] = 1;
				q.push({ nr, nc });
			}
		}

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				if (!map[i][j]) continue;
				int c = 0;
				for (int k = 0; k < 4; ++k) {
					int ni = i + dr[k], nj = j + dc[k];
					if (ni < 1 || ni > n) continue;
					if (nj < 1 || nj > m) continue;
					if (vis[ni][nj]) c++;
				}
				if (c > 1) map[i][j] = 0;
			}
	}
	cout << ans;
}