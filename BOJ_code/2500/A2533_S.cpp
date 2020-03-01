// BOJ 2533 사회망 서비스(SNS)
// Tree DP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mxn = 1000001;

vector<vector<int> > adj(mxn);
int dp[mxn][2];

void dfs(int cur, int prev = -1) {
	dp[cur][0] = 0;
	dp[cur][1] = 1;
	for (auto next : adj[cur])
		if (next != prev) {
			dfs(next, cur);
			dp[cur][0] += dp[next][1];
			dp[cur][1] += min(dp[next][0], dp[next][1]);
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

	dfs(1);
	cout << min(dp[1][0], dp[1][1]);
}