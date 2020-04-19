// BOJ 16293 Appalling Architecture
// ±¸Çö

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int h, w; cin >> h >> w;
	int grid[101][101] = {};
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			char c; cin >> c;
			if (c != '.') grid[i][j] = 1;
		}

	int cnt[101] = {};
	for (int j = 0; j < w; ++j)
		for (int i = 0; i < h; ++i)
			cnt[j] += grid[i][j];

	double l = 105, r = -1;
	for (int i = 0; i < w; ++i)
		if (grid[h - 1][i]) {
			l = min(l, (double)i - 0.5);
			r = i + 0.5;
		}

	int sum = 0, cc = 0;
	for (int i = 0; i < w; ++i) sum += cnt[i] * i, cc += cnt[i];

	if ((double)sum / cc < l) cout << "left";
	else if ((double)sum / cc > r) cout << "right";
	else cout << "balanced";
}