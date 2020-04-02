// BOJ 7569 ≈‰∏∂≈‰
// BFS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int i, j, k;
};

int tom[101][101][101], day[101][101][101];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, h; cin >> n >> m >> h;
	queue<node> Q;
	for (int k = 0; k < h; ++k)
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j) {
				cin >> tom[i][j][k];
				if (tom[i][j][k] == 1) {
					Q.push({ i, j, k });
					day[i][j][k] = 1;
				}
			}

	int dx[6] = { 0, 0, 0, -1, 0, 1 }, dy[6] = { 0, 0, 1, 0, -1, 0 }, dz[6] = { -1 ,1, 0, 0, 0, 0 };
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int k = 0; k < 6; ++k) {
			int nx = cur.i + dx[k], ny = cur.j + dy[k], nz = cur.k + dz[k];
			if (nx < 0 || nx >= m) continue;
			if (ny < 0 || ny >= n) continue;
			if (nz < 0 || nz >= h) continue;
			if (tom[nx][ny][nz] == -1) continue;
			if (day[nx][ny][nz]) continue;
			day[nx][ny][nz] = day[cur.i][cur.j][cur.k] + 1;
			Q.push({ nx, ny, nz });
		}
	}
	int ans = 0;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < h; ++k)
				if (day[i][j][k])ans = max(ans, day[i][j][k]);
				else if (tom[i][j][k] != -1) {
					cout << -1;
					return 0;
				}
	cout << ans - 1;
}