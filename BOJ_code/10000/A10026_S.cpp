// BOJ 10026 적록색약
// DFS

#include <iostream>
#include <cstring>
using namespace std;

bool vis[101][101];
char mat[101][101];
int n;
int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };

void dfs(int i, int j) {
	for (int k = 0; k < 4; ++k) {
		int ni = i + di[k], nj = j + dj[k];
		if (!(0 <= ni && ni < n)) continue;
		if (!(0 <= nj && nj < n)) continue;
		if (vis[ni][nj] || mat[i][j] != mat[ni][nj]) continue;
		vis[ni][nj] = true;
		dfs(ni, nj);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> mat[i][j];

	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (vis[i][j]) continue;
			vis[i][j] = true;
			dfs(i, j);
			ans++;
		}
	cout << ans << ' ';

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (mat[i][j] == 'G') mat[i][j] = 'R';

	ans = 0;
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (vis[i][j]) continue;
			vis[i][j] = true;
			dfs(i, j);
			ans++;
		}
	cout << ans << ' ';
}