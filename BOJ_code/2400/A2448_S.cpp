// BOJ 2448 별 찍기 - 11
// 재귀

#include <iostream>
using namespace std;

char star[3100][6200];

void go(int i, int j, int c) {
	if (c == 3) {
		star[i][j + 2] = star[i + 1][j + 1] = star[i + 1][j + 3] = '*';
		for (int k = j; k < j + 5; ++k) star[i + 2][k] = '*';
	}
	else {
		c /= 2;
		go(i, j + c, c);
		go(i + c, j, c);
		go(i + c, j + 2 * c, c);
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int c; cin >> c;
	for (int i = 0; i < c; ++i) for (int j = 0; j < 2 * c; ++j) star[i][j] = ' ';
	go(0, 0, c);
	for (int i = 0; i < c; ++i) {
		for (int j = 0; j < 2 * c - 1; ++j) cout << star[i][j];
		if (i < c - 1)cout << '\n';
	}
}