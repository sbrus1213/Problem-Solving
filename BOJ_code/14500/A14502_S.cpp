// BOJ 14502 연구소
// brute force & dfs bfs

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	int map[8][8];
	vector<pii> empty, virus;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 0) empty.push_back({ i, j });
			else if (map[i][j] == 2) virus.push_back({ i, j });
		}

	int en = empty.size(), dr[] = { 1, 0, -1, 0 }, dc[] = { 0, 1, 0, -1 }, ans = 0;
	for (int i = 0; i < en; ++i) for (int j = i + 1; j < en; ++j) for (int k = j + 1; k < en; ++k) {
		map[empty[i].first][empty[i].second] = 1;
		map[empty[j].first][empty[j].second] = 1;
		map[empty[k].first][empty[k].second] = 1;

		queue<pii> q;
		int go[8][8] = {};
		for (auto p : virus)
			q.push(p), go[p.first][p.second] = 1;

		while (!q.empty()) {
			auto t = q.front(); q.pop();
			int r = t.first, c = t.second;
			for (int l = 0; l < 4; ++l) {
				int nr = r + dr[l], nc = c + dc[l];
				if (nr < 0 || nr >= n) continue;
				if (nc < 0 || nc >= m) continue;
				if (go[nr][nc] || map[nr][nc] == 1) continue;
				go[nr][nc] = 1;
				q.push(pii(nr, nc));
			}
		}

		int c = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (!map[i][j] && !go[i][j])
					c++;

		ans = max(ans, c);

		map[empty[i].first][empty[i].second] = 0;
		map[empty[j].first][empty[j].second] = 0;
		map[empty[k].first][empty[k].second] = 0;
	}

	cout << ans;
}