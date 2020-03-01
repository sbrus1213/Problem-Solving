// BOJ 7576 ≈‰∏∂≈‰
// BFS

#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int n, m, mat[1001][1001], day[1001][1001];
int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };
queue<pii> Q;

void bfs() {
	while (!Q.empty()) {
		auto curr = Q.front();
		Q.pop();
		for (int k = 0; k < 4; ++k) {
			int ni = curr.first + di[k], nj = curr.second + dj[k];
			if (!(0 <= ni && ni < n)) continue;
			if (!(0 <= nj && nj < m)) continue;
			if (day[ni][nj] || mat[ni][nj] == -1) continue;
			day[ni][nj] = day[curr.first][curr.second] + 1;
			Q.push(pii(ni, nj));
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> m >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> mat[i][j];
			if (mat[i][j] == 1) {
				Q.push(pii(i, j));
				day[i][j] = 1;
			}
		}

	bfs();

	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (mat[i][j] != -1) {
				if (day[i][j] == 0) {
					cout << -1;
					return 0;
				}
				else ans = max(ans, day[i][j]);
			}
		}
	cout << ans - 1;
}