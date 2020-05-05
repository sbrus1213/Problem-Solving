// BOj 1261 알고스팟
// dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
const int inf = 1e8;

int n, m;
vector<vector<pii>> adj;
int dist[101][101];

void dijk() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, 0 });
	dist[1][1] = 0;
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		while (!pq.empty() && pq.top() == cur) pq.pop();
		int ci = cur.second / m + 1, cj = cur.second % m + 1;
		if (ci == n && cj == m) break;
		for (auto& nxt : adj[cur.second]) {
			int ni = nxt.first / m + 1, nj = nxt.first % m + 1;
			if (dist[ni][nj] > dist[ci][cj] + nxt.second) {
				dist[ni][nj] = dist[ci][cj] + nxt.second;
				pq.push(pii(dist[ni][nj], nxt.first));
			}
		}
	}
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> m;
	swap(n, m);

	adj = vector<vector<pii>>((n + 1) * (m + 1));
	int board[101][101];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			char c; cin >> c;
			board[i][j] = c - '0';
		}

	int di[] = { 1, 0, -1, 0 }, dj[] = { 0, 1, 0, -1 };
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (i * j == n * m) continue;
			for (int k = 0; k < 4; ++k) {
				int ni = i + di[k], nj = j + dj[k];
				if (ni < 1 || ni > n) continue;
				if (nj < 1 || nj > m) continue;
				if (board[ni][nj]) adj[(i - 1) * m + j - 1].push_back(pii((ni - 1) * m + nj - 1, 1));
				else adj[(i - 1) * m + j - 1].push_back(pii((ni - 1) * m + nj - 1, 0));
			}
		}

	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) dist[i][j] = inf;
	dijk();
	cout << dist[n][m];
}