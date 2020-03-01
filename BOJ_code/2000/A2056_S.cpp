// BOJ 2056 ÀÛ¾÷
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

	int n;
	cin >> n;

	vector<int> time(n + 1), mxtime(n + 1), ind(n + 1);
	vector<vector<int> > adj(n + 1);
	for (int i = 1; i <= n; ++i) {
		int cnt;
		cin >> time[i] >> cnt;
		for (int j = 0; j < cnt; ++j) {
			int pre;
			cin >> pre;
			adj[pre].push_back(i);
			ind[i]++;
		}
	}

	queue<pii > Q;
	for (int i = 1; i <= n; ++i)
		if (!ind[i]) {
			mxtime[i] = time[i];
			Q.push(pii(time[i], i));
		}

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int next : adj[cur.second]) {
			ind[next]--;
			mxtime[next] = max(mxtime[next], cur.first + time[next]);
			if (!ind[next]) Q.push(pii(mxtime[next], next));
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) ans = max(ans, mxtime[i]);

	cout << ans;
}