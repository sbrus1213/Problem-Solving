// BOJ 1865 ¿úÈ¦
// Bellman-Ford Algorithm

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <set>
#include <tuple>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;
#define ll	long long
#define BtoE(vec) vec.begin(), vec.end()
#define Pii pair<int, int>
#define Psi pair<string, int>
#define Tii tuple<int, int, int>
#define INF (1e9 + 7)

struct edge {
	int from, to, cost;
};
vector<int> dist(501);

bool bellman_ford(vector<edge>& edges) {
	int i, l = edges.size();
	bool flag = false;

	for (i = 0; i < l; ++i) {
		edge tmp = edges[i];

		if (dist[tmp.from] != INF && dist[tmp.to] > dist[tmp.from] + tmp.cost) {
			dist[tmp.to] = dist[tmp.from] + tmp.cost;
			flag = true;
		}
	}
	return flag;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	int tc;

	cin >> tc;

	while (tc--) {
		int n, m, w, i;
		vector<edge> edges;

		cin >> n >> m >> w;

		for (int i = 0; i < m + w; ++i) {
			int s, e, t;

			cin >> s >> e >> t;

			if (i < m) {
				edges.push_back({ s, e, t });
				edges.push_back({ e, s, t });
			}
			else edges.push_back({ s, e, -t });
		}

		for (i = 1; i <= n; ++i) {
			int j;

			fill(BtoE(dist), INF);
			dist[i] = 0;

			for (j = 0; j < n; ++j)
				if (!bellman_ford(edges))
					break;

			if (j == n) {
				cout << "YES\n";
				break;
			}
		}
		if (i == n + 1) cout << "NO\n";
	}
}