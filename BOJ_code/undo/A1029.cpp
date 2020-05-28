// BOJ 1029 그림 교환
// Bitwise DP

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int dp[1 << 16][16];
int buy[16][16];
vector<int> vis;
vector<vector<int>> adj;

void dfs(int cur, int prv) {
	for(int i = 1;i <= n;++i) {
		int nxt = i;
		if (buy[prv][cur] <= buy[cur][nxt]) {

		}
	}
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int c; cin >> c;
			buy[i][j] = c - '0';
		}
	}

	for (int i = 0; i < (1 << (n+1)); ++i)
		for (int j = 0; j <= n; ++j)
			dp[i][j] = -1;

	dp[3][1] = 1;
	for (int i = 3; i < (1 << (n + 1)); ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!(i & (1 << j))) continue;
			for (int k = 1; k <= n; ++k) {
				if (i & (1 << k)) continue;
				if()
				dp[i | (1 << k)][k] = max(dp[i | (1 << k)][k], dp[i][j] + 1);
			}
		}
	}
}
