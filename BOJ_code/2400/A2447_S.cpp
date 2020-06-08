// BOJ 2447 별 찍기 - 10
// 재귀

#include <iostream>
using namespace std;

char star[2200][2200];

void go(int i, int j, int c) {
	if (c == 1) star[i][j] = '*';
	else {
		c /= 3;
		go(i, j, c);
		go(i, j + c, c);
		go(i, j + 2 * c, c);
		go(i + c, j, c);
		go(i + c, j + 2 * c, c);
		go(i + 2 * c, j, c);
		go(i + 2 * c, j + c, c);
		go(i + 2 * c, j + 2 * c, c);
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int c; cin >> c;
	for (int i = 0; i < c; ++i) for (int j = 0; j < c; ++j) star[i][j] = ' ';
	go(0, 0, c);
	for (int i = 0; i < c; ++i) {
		for (int j = 0; j < c; ++j) cout << star[i][j];
		cout << '\n';
	}
}