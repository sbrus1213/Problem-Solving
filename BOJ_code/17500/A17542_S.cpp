// BOJ 17542 Architecture
// simulation

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r, c; cin >> r >> c;

	int row[101], col[101], grid[101][101];
	for (int i = 0; i < r; ++i) cin >> row[i];
	for (int i = 0; i < c; ++i) cin >> col[i];
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			grid[i][j] = min(row[i], col[j]);
	for (int i = 0; i < r; ++i) {
		int t = 0;
		for (int j = 0; j < c; ++j) t = max(t, grid[i][j]);
		if (t != row[i]) {
			cout << "impossible";
			return 0;
		}
	}
	for (int j = 0; j < c; ++j) {
		int t = 0;
		for (int i = 0; i < r; ++i) t = max(t, grid[i][j]);
		if (t != col[j]) {
			cout << "impossible";
			return 0;
		}
	}
	cout << "possible";
}