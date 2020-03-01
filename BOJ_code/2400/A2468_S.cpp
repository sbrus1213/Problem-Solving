// BOJ 2468 안전 영역
// BFS

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool vis[101][101];
int height[101][101], n, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

void dfs(int i, int j) {
	vis[i][j] = 1;

	for (int k = 0; k < 4; ++k) {
		int ni = i + dx[k], nj = j + dy[k];
		if (ni >= 0 && nj >= 0 && ni < n && nj < n)
			if (!vis[ni][nj])
				dfs(ni, nj);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> height[i][j];

	int res = 0;

	for (int h = 0; h < 100; ++h) {
		int cnt = 0;
		memset(vis, 0, sizeof(vis));

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (height[i][j] <= h)
					vis[i][j] = 1;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (!vis[i][j]) {
					dfs(i, j);
					++cnt;
				}

		res = max(res, cnt);
	}

	cout << res;
}