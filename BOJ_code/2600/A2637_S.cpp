// BOJ 2637 장난감 조립
// Topological sort

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<pii > > radj(n + 1);
	vector<int> rind(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> v >> u >> w;
		radj[v].push_back({ u, w });
		rind[u]++;
	}

	queue<int> Q;
	for (int i = 1; i <= n; ++i)
		if (!rind[i])
			Q.push(i);

	vector<int> cnt(n + 1), ans;
	cnt[n] = 1;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (auto& next : radj[cur]) {
			rind[next.first]--;
			cnt[next.first] += cnt[cur] * next.second;
			if (!rind[next.first]) Q.push(next.first);
		}
		if (!radj[cur].size()) ans.push_back(cur);
	}

	sort(ans.begin(), ans.end());
	for (int elem : ans) cout << elem << ' ' << cnt[elem] << '\n';
}