// BOj 2206 벽 부수고 이동하기
// BFS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int r, c, br;
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	char b[1001][1001];
	for (int i = 0; i < n; ++i) cin >> b[i];

	int di[] = { 1, 0, -1, 0 }, dj[] = { 0, -1, 0, 1 };
	bool chk1[1001][1001] = { true, }, chk2[1001][1001] = { true, };
	int d1[1001][1001] = { 1, }, d2[1001][1001] = { 1, };
	queue<node> Q;
	Q.push({ 0, 0, 1 });
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int k = 0; k < 4; ++k) {
			int nx = cur.r + di[k], ny = cur.c + dj[k];
			if (nx < 0 || nx >= n) continue;
			if (ny < 0 || ny >= m) continue;
			if (b[nx][ny] == '1') {
				if (cur.br && !chk2[nx][ny]) {
					d2[nx][ny] = d1[cur.r][cur.c] + 1;
					chk2[nx][ny] = true;
					Q.push({ nx, ny, 0 });
				}
			}
			else if (cur.br) {
				if (chk1[nx][ny]) continue;
				d1[nx][ny] = d1[cur.r][cur.c] + 1;
				chk1[nx][ny] = true;
				Q.push({ nx, ny, 1 });
			}
			else {
				if (chk2[nx][ny]) continue;
				d2[nx][ny] = d2[cur.r][cur.c] + 1;
				chk2[nx][ny] = true;
				Q.push({ nx, ny, 0 });
			}
		}
	}
	if (d1[n - 1][m - 1] && d2[n - 1][m - 1]) cout << min(d1[n - 1][m - 1], d2[n - 1][m - 1]);
	else if (d1[n - 1][m - 1]) cout << d1[n - 1][m - 1];
	else if (d2[n - 1][m - 1]) cout << d2[n - 1][m - 1];
	else cout << -1;
}