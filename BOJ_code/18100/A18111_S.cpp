// BOJ 18111 마인크래프트
// Brute force

#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1e9

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, b;
	cin >> n >> m >> b;

	if (!n || !m) {
		cout << 0 << ' ' << 0;
		return 0;
	}

	int block[500][500], l = 500, h = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> block[i][j];
			l = min(l, block[i][j]);
			h = max(h, block[i][j]);
		}
	}

	if (l == h) cout << 0 << ' ' << l;
	else {
		int up, down, h_res = l, t_res = INF;
		for (int i = l; i <= h; ++i) {
			up = down = 0;

			for (int j = 0; j < n; ++j)
				for (int k = 0; k < m; ++k)
					if (block[j][k] > i) up += block[j][k] - i;
					else if (block[j][k] < i) down += i - block[j][k];

			if (b + up >= down) {
				if (t_res > up * 2 + down) {
					t_res = up * 2 + down;
					h_res = i;
				}
				else if (t_res == up * 2 + down)
					h_res = i;
			}
		}
		cout << t_res << ' ' << h_res;
	}
}