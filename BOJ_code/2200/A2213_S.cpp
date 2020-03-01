// BOJ 2213 트리의 독립집합
// Tree DP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mxn = 10001;

vector<vector<int> > adj(mxn);
vector<int> res;
int dp[mxn][2], w[mxn];

void dfs(int cur, int prev = -1) {
	dp[cur][1] = w[cur];
	for (auto next : adj[cur])
		if (next != prev) {
			dfs(next, cur);
			dp[cur][0] += max(dp[next][0], dp[next][1]);
			dp[cur][1] += dp[next][0];
		}
}
void trace(int flag, int cur, int prev = -1) {
	if (!flag) {
		for (auto next : adj[cur]) {
			if (next == prev) continue;
			if (dp[next][0] > dp[next][1])
				trace(0, next, cur);
			else trace(1, next, cur);
			trace(2, next, cur);
		}
	}
	else if (flag == 1) {
		res.push_back(cur);
		for (auto next : adj[cur]) {
			if (next == prev) continue;
			trace(0, next, cur);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) cin >> w[i];

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans;
	dfs(1);
	ans = max(dp[1][0], dp[1][1]);

	if (ans == dp[1][1]) trace(1, 1);
	else trace(0, 1);
	sort(res.begin(), res.end());

	cout << ans << '\n';
	for (auto x : res) cout << x << ' ';
}