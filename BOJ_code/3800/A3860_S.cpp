// BOJ 3860 ÇÒ·ÎÀ© ¹¦Áö
// Bellman ford

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int INF = 1e9 + 7;

struct edge {
	int fromx, fromy, tox, toy, cost;
};

int n, m;
int dist[31][31];
bool grave[31][31], ghost[31][31];
vector<edge> E;

bool bmf() {
	bool flag = false;
	for (auto& e : E) {
		int fx = e.fromx, fy = e.fromy, tx = e.tox, ty = e.toy, c = e.cost;
		if (dist[fx][fy] != INF && dist[tx][ty] > dist[fx][fy] + c) {
			dist[tx][ty] = dist[fx][fy] + c;
			flag = true;
		}
	}
	return flag;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (cin >> n >> m) {
		if (!n) break;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				dist[i][j] = INF;
		dist[0][0] = 0;

		int c;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				grave[i][j] = false;
		cin >> c;
		for (int i = 0; i < c; ++i) {
			int a, b;
			cin >> a >> b;
			grave[a][b] = true;
		}

		E.clear();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				ghost[i][j] = false;
		cin >> c;
		for (int i = 0; i < c; ++i) {
			int a, b, c, d, w;
			cin >> a >> b >> c >> d >> w;
			if (grave[a][b]) continue;
			ghost[a][b] = true;
			E.push_back({ a, b, c, d, w });
		}

		int di[4] = { 1, 0, -1, 0 }, dj[4] = { 0, 1, 0, -1 };
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grave[i][j] || ghost[i][j]) continue;
				if (i == n - 1 && j == m - 1) break;
				for (int k = 0; k < 4; ++k) {
					int ii = i + di[k], jj = j + dj[k];
					if (!(ii >= 0 && jj >= 0 && ii < n && jj < m)) continue;
					if (grave[ii][jj]) continue;
					E.push_back({ i, j, ii, jj, 1 });
				}
			}
		}

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (i || j)
					bmf();

		if (bmf()) cout << "Never\n";
		else if (dist[n - 1][m - 1] == INF) cout << "Impossible\n";
		else cout << dist[n - 1][m - 1] << '\n';
	}
}