// BOJ 17129 윌리암슨수액빨이딱따구리가 정보섬에 올라온 이유
// BFS

#include <iostream>
#include <queue>
using namespace std;

int map[3000][3000], vis[3000][3000];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	int si, sj;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c; cin >> c;
			map[i][j] = c - '0';
			if (map[i][j] == 2) si = i, sj = j;
		}
	}
	queue<int> q;
	q.push(si * m + sj);
	vis[si][sj] = 1;
	int di[] = { 1,0,-1,0 }, dj[] = { 0,1,0,-1 }, ans = 0;
	while (!q.empty()) {
		int c = q.front(); q.pop();
		int ci = c / m, cj = c % m;
		for (int i = 0; i < 4; ++i) {
			int ni = ci + di[i], nj = cj + dj[i];
			if (ni < 0 || ni >= n) continue;
			if (nj < 0 || nj >= m) continue;
			if (vis[ni][nj] || map[ni][nj] == 1) continue;
			vis[ni][nj] = vis[ci][cj] + 1;
			q.push(ni * m + nj);
			if (map[ni][nj] > 2) {
				ans = vis[ni][nj] - 1;
				break;
			}
		}
		if (ans) break;
	}
	if (ans) cout << "TAK\n" << ans;
	else cout << "NIE";
}