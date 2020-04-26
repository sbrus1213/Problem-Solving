// BOJ 9205 맥주 마시면서 걸어가기
// BFS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

inline int dist(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;

		vector<pii> p(n + 2);
		for (int i = 0; i < n + 2; ++i) cin >> p[i].first >> p[i].second;

		vector<bool> go(n + 2);
		queue<int> q;

		go[0] = 1;
		q.push(0);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			if (cur == n + 1) break;

			for (int i = 1; i < n + 2; ++i) {
				if (i == cur || go[i]) continue;
				if (dist(p[cur], p[i]) <= 1000) {
					go[i] = 1;
					q.push(i);
				}
			}
		}

		if (go[n + 1]) cout << "happy\n";
		else cout << "sad\n";
	}
}