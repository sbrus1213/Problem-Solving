// BOJ 5573 ªÍ√•
// Dynamic Programming

#include <iostream>
using namespace std;

int direc[1001][1001], cnt[1001][1001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;

	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> direc[i][j];

	cnt[0][0] = k - 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cnt[i + 1][j] += cnt[i][j] / 2;

			cnt[i][j + 1] += cnt[i][j] / 2;

			if (cnt[i][j] % 2) {
				if (direc[i][j])
					cnt[i][j + 1]++;
				else
					cnt[i + 1][j]++;
			}

			direc[i][j] ^= (cnt[i][j] % 2);
		}
	}

	int i = 0, j = 0;
	while (i < n && j < m) {
		if (direc[i][j]) ++j;
		else ++i;
	}

	cout << i + 1 << ' ' << j + 1;
}