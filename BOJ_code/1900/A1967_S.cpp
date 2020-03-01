// BOJ 1967 트리의 지름
// Tree DP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int mxn = 10001;

vector<vector<pii> > gadj(mxn);
int dp[mxn], mx[mxn];

int dfs(int cur) {
	dp[cur] = 0;
	mx[cur] = 0;
	int& ret = dp[cur];
	for (auto next : gadj[cur]) {
		ret = max(ret, dfs(next.first));
		mx[cur] = max(mx[cur], mx[next.first] + next.second);
	}
	if (gadj[cur].size() == 1)
		ret = max(ret, mx[gadj[cur][0].first] + gadj[cur][0].second);
	else if (gadj[cur].size() > 1) {
		vector<int> tmp;
		for (auto next : gadj[cur])
			tmp.push_back(mx[next.first] + next.second);
		sort(tmp.begin(), tmp.end(), greater<int>());
		ret = max(ret, tmp[0] + tmp[1]);
	}
	return ret;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		gadj[u].push_back(pii(v, w));
	}

	cout << dfs(1);
}