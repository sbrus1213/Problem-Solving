// BOJ 14267 내리 칭찬
// dynamic programming & dfs

#include <iostream>
#include <vector>
using namespace std;
const int mxn = 100001;
using ll = long long;

vector<int> adj[mxn];
int ching[mxn];

void dfs(int cur, int down = 0) {
	ching[cur] += down;
	for (int nxt : adj[cur]) {
		dfs(nxt, ching[cur]);
	}
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		int par; cin >> par;
		if (par > 0) adj[par].push_back(i);
	}

	for (int i = 0; i < m; ++i) {
		int idx, chan; cin >> idx >> chan;
		ching[idx] += chan;
	}

	dfs(1);

	for (int i = 1; i <= n; ++i) cout << ching[i] << ' ';
}