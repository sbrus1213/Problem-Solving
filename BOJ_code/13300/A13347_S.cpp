// BOJ 13347 Lost In The Woods
// dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	double mat[21][21] = {};
	int deg[21] = {};
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		mat[u][v] = mat[v][u] = 1;
		deg[u] += 1;
		deg[v] += 1;
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			mat[i][j] /= deg[i];

	double ans = 0, exp[21] = { 1, };
	for (int cc = 1; cc <= 10000; ++cc) {
		double tmp[21] = {};
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				tmp[i] += mat[j][i] * exp[j];
		for (int i = 0; i < n; ++i)
			exp[i] = tmp[i];
		ans += exp[n - 1] * (double)cc;
		exp[n - 1] = 0;
	}
	cout << fixed;
	cout.precision(6);
	cout << ans;
}