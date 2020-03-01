// BOJ 17831 대기업 승범이네
// Tree DP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mxn = 200001;

vector<vector<int> > adj(mxn);
int dp[mxn][3], w[mxn];

void dfs(int cur, int prev = -1) {
	int sum = 0;
	for (auto next : adj[cur])
		if (next != prev) {
			dfs(next, cur);
			sum += max(dp[next][0], dp[next][2]);
		}
	dp[cur][2] = dp[cur][1] = sum;
	for (auto next : adj[cur])
		if (next != prev)
			dp[cur][0] = max(dp[cur][0], sum - max(dp[next][0], dp[next][2]) + w[cur] * w[next] + dp[next][1]);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		adj[p].push_back(i);
	}
	for (int i = 1; i <= n; ++i) cin >> w[i];

	dfs(1);
	cout << max(dp[1][0], max(dp[1][1], dp[1][2]));
}