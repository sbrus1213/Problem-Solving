// BOJ 5549 Çà¼º Å½»ç
// prefix sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char s[3] = { 'J','O','I' };
int sec[3][1001][1001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char x; cin >> x;
			for (int l = 0; l < 3; ++l) {
				sec[l][i][j] = sec[l][i - 1][j] + sec[l][i][j - 1] - sec[l][i - 1][j - 1];
				if (x == s[l]) sec[l][i][j]++;
			}
		}
	}

	for (int i = 0; i < k; ++i) {
		int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
		for (int j = 0; j < 3; ++j)
			cout << sec[j][ex][ey] - sec[j][ex][sy - 1] - sec[j][sx - 1][ey] + sec[j][sx - 1][sy - 1] << ' ';
		cout << '\n';
	}
}