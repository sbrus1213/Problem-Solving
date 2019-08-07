// BOJ 11660 구간 합 구하기 5
// Prefix Sum

#include <iostream>
using namespace std;

int prefixsum[1025][1025] = { 0 };

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int x;

			cin >> x;

			prefixsum[i][j] = prefixsum[i][j - 1] + prefixsum[i - 1][j] - prefixsum[i - 1][j - 1] + x;
		}
	}

	for (int i = 0; i < m; ++i) {
		int x1, x2, y1, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		cout << prefixsum[x2][y2] - prefixsum[x1 - 1][y2] - prefixsum[x2][y1 - 1] + prefixsum[x1 - 1][y1 - 1] << '\n';
	}
}