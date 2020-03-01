// BOJ 16404 주식회사 승범이네
// sqrt Decomposition

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

struct sqrtD
{
	int n, bsz, bcnt;
	vector<ll> arr, bucket;
	sqrtD(int n) : n(n), bsz(sqrt(n)), bcnt(sqrt(n) + 1) {
		arr.resize(n);
		bucket.resize(bcnt);
	}
	void update(int l, int r, ll diff) {
		while (l <= r && l % bsz)
			arr[l++] += diff;
		while (l <= r && (r + 1) % bsz)
			arr[r--] += diff;
		while (l <= r) {
			bucket[l / bsz] += diff;
			l += bsz;
		}
	}
	ll query(int idx) {
		return arr[idx] + bucket[idx / bsz];
	}
};

int t;

void dfs(int u, vector<vector<int> >& adj, vector<int>& L, vector<int>& R) {
	L[u] = ++t;
	for (int v : adj[u])
		dfs(v, adj, L, R);
	R[u] = t;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	sqrtD B(n);
	vector<vector<int> > adj(n + 1);
	vector<int> L(n + 1), R(n + 1);

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (i > 1) adj[x].push_back(i);
	}
	dfs(1, adj, L, R);

	for (int i = 0; i < m; ++i) {
		int comm, idx, w;
		cin >> comm >> idx;
		if (comm == 1) {
			cin >> w;
			B.update(L[idx] - 1, R[idx] - 1, w);
		}
		else cout << B.query(L[idx] - 1) << '\n';
	}
}