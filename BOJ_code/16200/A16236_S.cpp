// BOJ 16236 아기 상어
// bfs

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
using pii = pair<int, int>;

struct fish {
	int r, c, w;
	fish() : fish(0, 0, 0) {}
	fish(int r_, int c_, int w_) : r(r_), c(c_), w(w_) {}
};
bool operator< (fish a, fish b) {
	if (a.w == b.w) {
		if (a.r == b.r) return a.c < b.c;
		return a.r < b.r;
	}
	return a.w < b.w;
}

int dr[] = { 1, 0, -1, 0 }, dc[] = { 0, -1, 0, 1 };

fish bfs(vector<vector<int>>& map, int sr, int sc, int sz) {
	int n = map.size();
	queue<pii> q;
	q.push({ sr, sc });
	vector<vector<int>> dist(n, vector<int>(n));
	dist[sr][sc] = 1;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int r = cur.first, c = cur.second;
		for (int k = 0; k < 4; ++k) {
			int nr = r + dr[k], nc = c + dc[k];
			if (nr < 0 || nr >= n) continue;
			if (nc < 0 || nc >= n) continue;
			if (dist[nr][nc]) continue;
			if (map[nr][nc] > sz) continue;
			dist[nr][nc] = dist[r][c] + 1;
			q.push({ nr, nc });
		}
	}

	vector<fish> candi;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (dist[i][j])
				if (map[i][j] && map[i][j] < sz)
					candi.push_back({ i, j, dist[i][j] - 1 });

	if (candi.empty()) return fish(0, 0, -1);

	sort(candi.begin(), candi.end());
	return candi[0];
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	int sr, sc;
	vector<fish> pos;
	vector<vector<int>> map(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			if (!map[i][j]) continue;
			else if (map[i][j] == 9) sr = i, sc = j;
			else pos.push_back(fish(i, j, map[i][j]));
		}

	map[sr][sc] = 0;
	int sz = 2, t = 0, ans = 0;
	while (pos.size()) {
		auto go = bfs(map, sr, sc, sz);

		if (go.w == -1) break;

		ans += go.w;
		sr = go.r;
		sc = go.c;
		map[sr][sc] = 0;

		if (sz == ++t) sz++, t = 0;
	}

	cout << ans;
}