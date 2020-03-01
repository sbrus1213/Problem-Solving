// BOJ 1289 트리의 가중치
// Tree DP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;
const int MXN = 100001;

vector<vector<pll > > adj(MXN);
ll dp[MXN][3];

void dfs(int cur, int prev = -1) {
	ll temp = 0;

	for (auto next : adj[cur]) {
		if (next.first != prev) {
			dfs(next.first, cur);

			dp[cur][0] = (dp[cur][0] + next.second + (dp[next.first][0] * next.second) % MOD) % MOD;

			dp[cur][1] = (dp[cur][1] + (temp * (((dp[next.first][0] + 1) * next.second) % MOD)) % MOD) % MOD;
			temp = (temp + ((dp[next.first][0] + 1) * next.second) % MOD) % MOD;

			dp[cur][2] = (dp[cur][2] + dp[next.first][0] + dp[next.first][1] + dp[next.first][2]) % MOD;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i < n; ++i) {
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(pll(v, w));
		adj[v].push_back(pll(u, w));
	}

	dfs(1);
	cout << (dp[1][0] + dp[1][1] + dp[1][2]) % MOD;
}