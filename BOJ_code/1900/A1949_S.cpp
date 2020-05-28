// BOJ 1949 우수 마을
// Tree DP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> town;
vector<vector<int>> adj, dp;

void go(int cur, int prv) {
	dp[cur][0] = town[cur];
	int mn = 1e9;
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		else {
			go(nxt, cur);
			dp[cur][0] += max(dp[nxt][1], dp[nxt][2]);
			dp[cur][2] += dp[nxt][1];
			if (dp[nxt][0] >= dp[nxt][1]) {
				dp[cur][1] += dp[nxt][0];
				mn = min(mn, 0);
			}
			else {
				dp[cur][1] += dp[nxt][1];
				mn = min(mn, dp[nxt][1] - dp[nxt][0]);
			}
		}
	}
	if (mn != 1e9) dp[cur][1] -= mn;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	town = vector<int>(n + 1);
	for (int i = 1; i <= n; ++i) cin >> town[i];

	adj = vector<vector<int>>(n + 1);
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dp = vector<vector<int>>(n + 1, (vector<int>(3)));
	go(1, 0);

	cout << max({ dp[1][0], dp[1][1] });
}