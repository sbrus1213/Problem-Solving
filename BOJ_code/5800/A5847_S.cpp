// BOJ 5847 Milk scheduling
// Topological sort

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<ll> time(n + 1), mxtime(n + 1);
	vector<int> ind(n + 1);
	vector<vector<int> > adj(n + 1);
	for (int i = 1; i <= n; ++i) cin >> time[i];
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		ind[b]++;
	}

	queue<pll > Q;
	for (int i = 1; i <= n; ++i)
		if (!ind[i]) {
			mxtime[i] = time[i];
			Q.push(pll(time[i], i));
		}

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int next : adj[cur.second]) {
			ind[next]--;
			mxtime[next] = max(mxtime[next], cur.first + time[next]);
			if (!ind[next]) Q.push(pll(mxtime[next], next));
		}
	}

	ll ans = 0;
	for (int i = 1; i <= n; ++i) ans = max(ans, mxtime[i]);

	cout << ans;
}