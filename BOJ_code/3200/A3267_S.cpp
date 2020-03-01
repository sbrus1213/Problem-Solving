// BOJ 3267 TWO
// Tree DP & 트리의 지름

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int mxn = 100001;

vector<vector<pii > > adj(mxn);
int dp[mxn], mx[mxn], sum;

int dfs(int cur, int prev = -1) {
	vector<int> mxtmp;

	for (auto next : adj[cur]) {
		if (next.first == prev) continue;
		sum += next.second;
		dp[cur] = max(dp[cur], dfs(next.first, cur));
		mxtmp.push_back(mx[next.first] + next.second);
	}

	if (mxtmp.size() == 1) {
		mx[cur] = mxtmp[0];
		dp[cur] = max(dp[cur], mx[cur]);
	}
	else if (mxtmp.size() > 1) {
		sort(mxtmp.begin(), mxtmp.end(), greater<int>());
		mx[cur] = mxtmp[0];
		dp[cur] = max(dp[cur], mxtmp[0] + mxtmp[1]);
	}
	return dp[cur];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, s;
	cin >> n >> s;

	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(pii(v, w));
		adj[v].push_back(pii(u, w));
	}

	dfs(s);
	cout << 2 * sum - dp[s];
}