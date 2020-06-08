// BOJ 17940 지하철
// dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int inf = 1e9;

struct node {
	int count, time, u;
};
bool operator < (node a, node b) {
	if (a.count == b.count) return a.time > b.time;
	return a.count < b.count;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vector<int> ab(n);
	for (int i = 0; i < n; ++i)
		cin >> ab[i];

	vector<vector<node>> adj(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x; cin >> x;
			if (!x) continue;
			if (ab[i] == ab[j]) adj[i].push_back({ 0, x, j });
			else adj[i].push_back({ 1, x, j });
		}
	}

	vector<int> count(n, inf), time(n, inf);
	count[0] = 0; time[0] = 0;
	priority_queue<node> pq;
	pq.push({ 0, 0, 0 });

	while (!pq.empty()) {
		auto tp = pq.top(); pq.pop();
		int cnt = tp.count, tm = tp.time, cur = tp.u;
		for (auto next : adj[cur]) {
			int ncnt = cnt + next.count, ntm = tm + next.time, nxt = next.u;
			if (count[nxt] > ncnt) {
				count[nxt] = ncnt;
				time[nxt] = ntm;
				pq.push({ ncnt, ntm, nxt });
			}
			else if (count[nxt] == ncnt && time[nxt] > ntm) {
				time[nxt] = ntm;
				pq.push({ ncnt, ntm, nxt });
			}
		}
	}

	cout << count[m] << ' ' << time[m];
}