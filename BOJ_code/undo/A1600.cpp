// BOJ 1600 ¸»ÀÌ µÇ°íÇÂ ¿ø¼þÀÌ
// bfs

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int k, w, h; cin >> k >> w >> h;

	int di1[] = { -2, -1, 1, 2, 2, 1, -1, -2 }, dj1[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int di2[] = { 0, 1, -1, 0 }, dj2[] = { 1, 0, 0, -1 };

	int map[201][201];
	for (int i = 0; i < w; ++i)
		for (int j = 0; j < h; ++j)
			cin >> map[i][j];
	
	int dist[201][201] = {};
	dist[0][0] = 1;
	queue<pii> q;
	q.push(pii(0, 0));
	for (int _ = 0; _ < k; ++_) {
		int c = q.size();
		while (c--) {
			pii t = q.front(); q.pop();
			int i = t.first, j = t.second;
			for (int k = 0; k < 8; ++k) {
				int ni = i + di1[k], nj = j + dj1[k];
				if (ni < 0 || ni >= w) continue;
				if (nj < 0 || nj >= h) continue;
				if (map[ni][nj] || dist[ni][nj]) continue;
				dist[ni][nj] = dist[i][j] + 1;
				q.push(pii(ni, nj));
			}
		}
	}

	while (q.size()) q.pop();

	for (int i = 0; i < w; ++i)
		for (int j = 0; j < h; ++j)
			if (dist[i][j])
				q.push(pii(i, j));

	while (!q.empty() && !dist[w - 1][h - 1]) {
		pii t = q.front(); q.pop();
		int i = t.first, j = t.second;
		for (int k = 0; k < 4; ++k) {
			int ni = i + di2[k], nj = j + dj2[k];
			if (ni < 0 || ni >= w) continue;
			if (nj < 0 || nj >= h) continue;
			if (map[ni][nj] || dist[ni][nj]) continue;
			dist[ni][nj] = dist[i][j] + 1;
			q.push(pii(ni, nj));
		}
	}

	cout << dist[w - 1][h - 1] - 1;
}