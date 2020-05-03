// BOJ 11092 Safe Passage
// dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int inf = 5e7;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<int> time(n);
	for (int i = 0; i < n; ++i) cin >> time[i];
	sort(time.begin(), time.end());

	vector<vector<pii>> adj(1 << n);

	for (int i = 0; i < (1 << n) - 1; ++i) {
		vector<int> al, go;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) al.push_back(j);
			else go.push_back(j);
		}

		int sz = go.size();
		if (sz == 1) adj[i].push_back(pii((1 << n) - 1, time[go[0]]));
		else if (sz == 2) {
			adj[i].push_back(pii(i | (1 << go[0]) | (1 << go[1]), max(time[go[0]], time[go[1]])));
		}
		else {
			for (int j = 0; j < sz; ++j) {
				for (int k = j + 1; k < sz; ++k) {
					int nxt = i | (1 << go[j]) | (1 << go[k]), d = min(go[j], go[k]);
					if (al.size()) d = min(d, al[0]);
					adj[i].push_back(pii(nxt ^ (1 << d), max(time[go[j]], time[go[k]]) + time[d]));
				}
			}
		}
	}


	int s = 0, e = (1 << n) - 1;
	vector<int> dist(1 << n, inf);
	dist[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(dist[s], s));
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		for (auto nxt : adj[cur.second]) {
			if (dist[nxt.first] > dist[cur.second] + nxt.second) {
				dist[nxt.first] = dist[cur.second] + nxt.second;
				pq.push(pii(dist[nxt.first], nxt.first));
			}
		}
	}
	cout << dist[e];
}