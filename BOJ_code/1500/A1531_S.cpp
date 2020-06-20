// BOJ 1531 투명
// 구현

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	int pos[101][101] = {};
	while (n--) {
		int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
		for (int i = r1; i <= r2; ++i)
			for (int j = c1; j <= c2; ++j)
				pos[i][j]++;
	}

	int ans = 0;
	for (int i = 1; i <= 100; ++i)
		for (int j = 1; j <= 100; ++j)
			if (pos[i][j] > m)
				ans++;

	cout << ans;
}