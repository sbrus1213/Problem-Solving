// BOJ 2167 2차원 배열의 합
// prefix sum

#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vector<vector<int>> pxs(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> pxs[i][j];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			pxs[i][j] += pxs[i - 1][j] + pxs[i][j - 1] - pxs[i - 1][j - 1];

	int q; cin >> q;
	while (q--) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		cout << pxs[rx][ry] - pxs[lx - 1][ry] - pxs[rx][ly - 1] + pxs[lx - 1][ly - 1] << '\n';
	}
}