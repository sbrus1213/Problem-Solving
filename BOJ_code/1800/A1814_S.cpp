// BOJ 1814 ÁöºØ »öÄ¥ÇÏ±â
// Tree DP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mxn = 10001;

vector<vector<int> > adj(mxn);
vector<int> paint(mxn);
int dp[mxn][4];

inline int min3(int a, int b, int c) {
	return min(a, min(b, c));
}

void dfs(int cur, int prev = -1) {
	for (int k = 0; k < 4; ++k) dp[cur][k] = paint[k];

	for (auto next : adj[cur])
		if (next != prev) {
			dfs(next, cur);
			dp[cur][0] += min3(dp[next][1], dp[next][2], dp[next][3]);
			dp[cur][1] += min3(dp[next][0], dp[next][2], dp[next][3]);
			dp[cur][2] += min3(dp[next][0], dp[next][1], dp[next][3]);
			dp[cur][3] += min3(dp[next][0], dp[next][1], dp[next][2]);
		}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int p;
	cin >> p;
	fill(paint.begin(), paint.end(), mxn * n);
	for (int i = 0; i < p; ++i) cin >> paint[i];
	sort(paint.begin(), paint.end());

	dfs(1);
	cout << min(dp[1][0], min3(dp[1][1], dp[1][2], dp[1][3]));
}