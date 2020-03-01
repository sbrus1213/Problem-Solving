// BOJ 1615 교차개수세기
// Segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
#define BtoE(vec) vec.begin(), vec.end()

struct seg {
	int half;
	vector<int> item;
	seg(int n) {
		for (half = 1; half < n; half <<= 1);
		item.resize(half * 2);
	}
	int sum(int l, int r) {
		int res = 0;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) res += item[l++];
			if (!(r % 2)) res += item[r--];
			l >>= 1, r >>= 1;
		}
		return res;
	}
	void update(int idx) {
		idx += half;
		item[idx]++;
		idx >>= 1;
		while (idx) {
			item[idx] = item[idx * 2] + item[idx * 2 + 1];
			idx >>= 1;
		}
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	ll res = 0;
	cin >> n >> m;

	seg S(n);
	vector<vector<int> > adj(n);

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u - 1].push_back(v - 1);
	}

	for (int i = 0; i < n; ++i) sort(BtoE(adj[i]));

	for (int u = 0; u < n; ++u) {
		for (auto v : adj[u])
			if (v != n - 1)
				res += S.sum(v + 1, n - 1);

		for (auto v : adj[u])
			S.update(v);
	}

	cout << res;
}