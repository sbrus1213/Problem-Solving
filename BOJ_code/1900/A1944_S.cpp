// BOJ 1944 복제 로봇
// BFS & MST

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

struct Edge {
	int u, v, w;
};
bool operator< (Edge a, Edge b) {
	return a.w > b.w;
}

vector<int> par;
int find(int i) {
	if (par[i] < 0) return i;
	return par[i] = find(par[i]);
}
bool merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return false;
	par[y] = x;
	return true;
}

vector<pii> key;
int n, miro[51][51], di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };
void bfs(int i, pii st, vector<Edge>& edge) {
	int dist[51][51] = {};
	dist[st.first][st.second] = 1;
	queue<pii> q;
	q.push(st);
	while (!q.empty()) {
		auto c = q.front(); q.pop();
		int ii = c.first, jj = c.second;
		for (int k = 0; k < 4; ++k) {
			int ni = ii + di[k], nj = jj + dj[k];
			if (ni < 0 || ni >= n) continue;
			if (nj < 0 || nj >= n) continue;
			if (miro[ni][nj] == 1) continue;
			if (dist[ni][nj]) continue;
			dist[ni][nj] = dist[ii][jj] + 1;
			q.push(pii(ni, nj));
			if (miro[ni][nj] < 0)
				edge.push_back({ i, -miro[ni][nj], dist[ni][nj] - 1 });
		}
	}
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int m; cin >> n >> m;

	int cnt = 0;
	pii st;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char c; cin >> c;
			if (c == '1') miro[i][j] = 1;
			else if (c == '0') miro[i][j] = 0;
			else if (c == 'S') {
				miro[i][j] = -(m + 1);
				st = pii(i, j);
			}
			else if (c == 'K') {
				miro[i][j] = -(++cnt);
				key.push_back(pii(i, j));
			}
		}
	}
	key.push_back(st);

	vector<Edge> edge;
	for (int i = 1; i < m + 2; ++i)
		bfs(i, key[i - 1], edge);
	sort(edge.begin(), edge.end(), [&](Edge a, Edge b) {
		return a.w < b.w;
		});

	int ans = 0, mc = 0;
	par = vector<int>(m + 2, -1);
	for (auto& e : edge)
		if (merge(e.u, e.v))
			ans += e.w, mc++;

	if (mc == m) cout << ans;
	else cout << -1;
}