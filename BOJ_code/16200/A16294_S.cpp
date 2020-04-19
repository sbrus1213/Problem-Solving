// BOJ 16294 Bee Problem
// dfs bfs

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int h, n, m;
int dx[] = { 0, 0, 1, 1, -1, -1 }, dy[] = { 2, -2, 1, -1, 1, -1 };
vector<string> bh;
vector<vector<bool> > vis;
int dfs(int i, int j) {
	int ret = 1;
	vis[i][j] = true;
	for (int k = 0; k < 6; ++k) {
		int ni = i + dx[k], nj = j + dy[k];
		if (ni < 0 || ni >= n) continue;
		if (nj < 0 || nj >= 2 * m - 1 + (ni % 2)) continue;
		if (vis[ni][nj]) continue;
		if (bh[ni][nj] == '#') continue;
		ret += dfs(ni, nj);
	}
	return ret;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> h >> n >> m;
	cin.ignore(1);

	bh = vector<string>(n);
	for (int i = 0; i < n; ++i)
		getline(cin, bh[i]);

	vis = vector<vector<bool> >(n, vector<bool>(2 * m));
	priority_queue<int> pq;
	for (int i = 0; i < n; ++i)
		for (int j = i % 2; j < 2 * m - 1 + (i % 2); j += 2)
			if (bh[i][j] == '.' && !vis[i][j])
				pq.push(dfs(i, j));

	int ans = 0;
	while (!pq.empty() && h) {
		int t = pq.top(); pq.pop();
		ans++;
		if (t >= h) break;
		h -= t;
	}
	cout << ans;
}