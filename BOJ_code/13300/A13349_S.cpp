// BOJ 13349 Millionaire Madness
// binary search & bfs

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	int map[1001][1001];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> map[i][j];

	bool chk[1001][1001];
	int low = -1, high = 1e9 + 1, dr[] = { 0, 1, 0, -1 }, dc[] = { -1, 0, 1, 0 };
	while (low + 1 < high) {
		int mid = (low + high) / 2;
		memset(chk, false, sizeof chk);
		chk[0][0] = 1;
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int cr = q.front() / m, cc = q.front() % m;
			q.pop();
			for (int k = 0; k < 4; ++k) {
				int nr = cr + dr[k], nc = cc + dc[k];
				if (nr < 0 || nr >= n) continue;
				if (nc < 0 || nc >= m) continue;
				if (map[nr][nc] - map[cr][cc] > mid) continue;
				if (chk[nr][nc]) continue;
				chk[nr][nc] = true;
				if (nr == n - 1 && nc == m - 1) while (!q.empty()) q.pop();
				q.push(nr * m + nc);
			}
		}

		if (chk[n - 1][m - 1]) high = mid;
		else low = mid;
	}
	cout << high;
}