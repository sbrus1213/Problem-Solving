// BOJ 1012 ¿Ø±‚≥Û πË√ﬂ
// BFS DFS

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool visi[51][51];
int n, m, k, bat[51][51];
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

void dfs(int i, int j) {
	for (int k = 0; k < 4; ++k) {
		int ni = i + dx[k], nj = j + dy[k];
		if (!(0 <= ni && ni < n && 0 <= nj && nj < m)) continue;
		if (!bat[ni][nj] || visi[ni][nj]) continue;
		visi[ni][nj] = true;
		dfs(ni, nj);
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(visi, false, sizeof(visi));
		memset(bat, 0, sizeof(bat));

		cin >> n >> m >> k;
		for (int i = 0; i < k; ++i) {
			int x, y;
			cin >> x >> y;
			bat[x][y] = 1;
		}

		int ans = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (bat[i][j] && !visi[i][j]) {
					visi[i][j] = true;
					dfs(i, j);
					ans++;
				}

		cout << ans << '\n';
	}
}