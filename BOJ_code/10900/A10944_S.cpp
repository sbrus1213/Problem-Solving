// BOJ 2448 별 찍기 - 19
// 구현

#include <iostream>
using namespace std;

char star[400][400];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	for (int i = 0; i < 4 * n; ++i) for (int j = 0; j < 4 * n; ++j) star[i][j] = ' ';
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i * 2; j <= 4 * (n - 1) - i * 2; ++j)
			star[i * 2][j] = star[4 * (n - 1) - i * 2][j] = '*';
		for (int j = 0; j <= i * 2; j += 2) {
			star[i * 2][j] = star[i * 2][4 * (n - 1) - j] = star[i * 2 + 1][j] = star[i * 2 + 1][4 * (n - 1) - j] = '*';
			star[4 * (n - 1) - i * 2][j] = star[4 * (n - 1) - i * 2][4 * (n - 1) - j] = '*';
			star[4 * (n - 1) - i * 2 - 1][j] = star[4 * (n - 1) - i * 2 - 1][4 * (n - 1) - j] = '*';
		}
	}
	for (int i = 0; i < n; ++i)
		star[2 * (n - 1)][i * 2] = star[2 * (n - 1)][4 * (n - 1) - i * 2] = '*';
	for (int i = 0; i < 4 * n - 3; ++i) {
		for (int j = 0; j < 4 * n - 3; ++j) cout << star[i][j];
		cout << '\n';
	}
}