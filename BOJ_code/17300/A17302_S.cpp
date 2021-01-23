// BOJ 17302 흰색으로 만들기
// Ad-hoc

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	char color[2020][2020];
	int res[2020][2020];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> color[i][j];

	int di[] = { 1, 0, -1, 0 };
	int dj[] = { 0, 1, 0, -1 };

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			res[i][j] = 2;
			for (int k = 0; k < 4; ++k) {
				int ni = i + di[k], nj = j + dj[k];
				if (ni < 0 || ni >= n) continue;
				if (nj < 0 || nj >= m) continue;
				if (color[ni][nj] == 'W') color[ni][nj] = 'B';
				else color[ni][nj] = 'W';
			}
		}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (color[i][j] == 'B')
				res[i][j] = 3;

	cout << 1 << '\n';
	for (int i = 0; i < n; ++i, cout << '\n')
		for (int j = 0; j < m; ++j)
			cout << res[i][j];

	return 0;
}