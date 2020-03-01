// BOJ 11014 да╢в 2
// min cut & bipartite matching

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int mxn = 81;

int n, m;
char board[mxn][mxn];
int num[mxn][mxn];
vector<bool> vis;
vector<int> from;
vector<int> point;
vector<vector<int> > adj;
int di[6] = { -1,-1,0,0,1,1 }, dj[6] = { -1,1,-1,1,-1,1 };

bool dfs(int cur) {
	if (vis[cur]) return false;
	vis[cur] = true;
	for (int next : adj[cur]) {
		if (from[next] == -1 || dfs(from[next])) {
			from[next] = cur;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		adj = vector<vector<int> >(n * m + 1);
		point.clear();

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> board[i][j];

		int cnt = 0, crash = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] == 'x') crash++;
				if (!(j % 2)) point.push_back(cnt);
				num[i][j] = cnt++;
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] == 'x') continue;
				for (int k = 0; k < 6; ++k) {
					int ii = i + di[k], jj = j + dj[k];
					if (ii < 0 || ii >= n) continue;
					if (jj < 0 || jj >= m) continue;
					if (board[ii][jj] == 'x') continue;
					adj[num[i][j]].push_back(num[ii][jj]);
				}
			}
		}

		int ans = 0;
		vis = vector<bool>(n * m + 1);
		from = vector<int>(n * m + 1, -1);
		for (int a = 0; a < point.size(); a++) {
			fill(vis.begin(), vis.end(), false);
			ans += dfs(point[a]);
		}
		cout << n * m - ans - crash << '\n';
	}
}