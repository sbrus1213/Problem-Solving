// BOJ 17144 미세먼지 안녕!
// 구현

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m, t; cin >> n >> m >> t;

	int map[50][50], a = -1, b = -1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				if (a != -1) b = i;
				else a = i;
			}
		}

	int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };
	for (int i = 0; i < t; ++i) {
		int tmp[50][50] = {};

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (map[i][j] < 1) continue;
				int sum = 0;
				for (int k = 0; k < 4; ++k) {
					int ni = i + di[k], nj = j + dj[k];
					if (ni < 0 || ni >= n) continue;
					if (nj < 0 || nj >= m) continue;
					if (map[ni][nj] == -1) continue;
					tmp[ni][nj] += map[i][j] / 5;
					sum += map[i][j] / 5;
				}
				tmp[i][j] += map[i][j] - sum;
			}
		}

		for (int i = a; i > 0; --i) tmp[i][0] = tmp[i - 1][0];
		for (int j = 0; j < m - 1; ++j) tmp[0][j] = tmp[0][j + 1];
		for (int i = 0; i < a; ++i) tmp[i][m - 1] = tmp[i + 1][m - 1];
		for (int j = m - 1; j > 1; --j) tmp[a][j] = tmp[a][j - 1];

		for (int i = b; i < n - 1; ++i) tmp[i][0] = tmp[i + 1][0];
		for (int j = 0; j < m - 1; ++j) tmp[n - 1][j] = tmp[n - 1][j + 1];
		for (int i = n - 1; i > b; --i) tmp[i][m - 1] = tmp[i - 1][m - 1];
		for (int j = m - 1; j > 1; --j) tmp[b][j] = tmp[b][j - 1];

		tmp[a][1] = tmp[b][1] = 0;
		tmp[a][0] = tmp[b][0] = -1;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				map[i][j] = tmp[i][j];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (map[i][j] > 0)
				ans += map[i][j];

	cout << ans;
}