// BOJ 13344 Chess Tournament
// union find & topological sort

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

vector<int> par;
int find(int x) {
	if (par[x] < 0) return x;
	return par[x] = find(par[x]);
}
void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	par[x] = y;
	return;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	par = vector<int>(n, -1);
	vector<pii> qr;
	for (int i = 0; i < m; ++i) {
		int a, b; char o; cin >> a >> o >> b;
		if (o == '=') merge(a, b);
		else qr.push_back({ a, b });
	}

	vector<vector<int> > adj(n);
	vector<int> ind(n);
	for (pii qry : qr) {
		if (find(qry.first) == find(qry.second)) {
			cout << "inconsistent";
			return 0;
		}
		else {
			adj[find(qry.first)].push_back(find(qry.second));
			ind[find(qry.second)]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < n; ++i)
		if (!ind[i]) q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : adj[cur]) {
			ind[nxt]--;
			if (!ind[nxt]) q.push(nxt);
		}
	}

	bool fl = true;
	for (int i = 0; i < n; ++i)if (ind[i]) fl = false;
	if (fl) cout << "consistent";
	else cout << "inconsistent";
}