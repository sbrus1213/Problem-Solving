// BOJ 2843 ¸¶ºí
// Offline query & union find

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct query {
	int c, v, res;
};

vector<int> par, E;
vector<bool> cut, cycle;
vector<query> Q;

int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}
void merge(int x, int y) {
	y = find(y);
	if (x == y) return;
	par[x] = y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	par = vector<int>(n + 1);
	E = vector<int>(n + 1);
	for (int i = 1; i <= n; ++i) cin >> E[i];

	int q; cin >> q;
	cut = vector<bool>(n + 1);
	for (int i = 0; i < q; ++i) {
		int c, v; cin >> c >> v;
		Q.push_back({ c, v });
		if (c == 2) cut[v] = true;
	}

	for (int i = 1; i <= n; ++i) par[i] = i;

	cycle = vector<bool>(n + 1);
	for (int i = 1; i <= n; ++i)
		if (!cut[i] && E[i]) {
			if (find(i) == find(E[i])) cycle[i] = true;
			merge(i, E[i]);
		}

	for (int i = q - 1; i >= 0; --i) {
		if (Q[i].c == 1) {
			int tmp = find(Q[i].v);
			if (cycle[tmp]) Q[i].res = -1;
			else Q[i].res = tmp;
		}
		else {
			if (!E[Q[i].v]) continue;
			if (find(Q[i].v) == find(E[Q[i].v]))
				cycle[Q[i].v] = true;
			else merge(Q[i].v, E[Q[i].v]);
		}
	}

	for (int i = 0; i < q; ++i) {
		if (Q[i].res == -1) cout << "CIKLUS\n";
		else if (Q[i].c == 1) cout << Q[i].res << '\n';
	}
}