// BOJ 17549 Hexagonal Rooks
// graph

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

inline bool isin(int r, int c) {
	if (c < 0 || c>10) return false;
	if (c < 6) {
		if (r >= 5 - c && r <= 15 + c) return true;
		else return false;
	}
	else {
		if (r >= c - 5 && r <= 25 - c) return true;
		else return false;
	}
}
int getpos(int r, int c) {
	if (c < 6) return 15 + c - (r - 1) * 2;
	else return 25 - c - (r - 1) * 2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s, e; cin >> s >> e;

	int sr, sc, er, ec;
	sc = s[0] - 'a';
	if (s.size() == 2) sr = getpos(s[1] - '0', sc);
	else sr = getpos((s[1] - '0') * 10 + s[2] - '0', sc);
	ec = e[0] - 'a';
	if (e.size() == 2) er = getpos(e[1] - '0', ec);
	else er = getpos((e[1] - '0') * 10 + e[2] - '0', ec);

	int can1[21][11] = {}, can2[21][11] = {};
	int dr[] = { -2, 2, 1, 1, -1, -1 }, dc[] = { 0, 0, -1, 1, -1, 1 };
	for (int k = 0; k < 6; ++k) {
		int nr = sr, nc = sc;
		while (isin(nr + dr[k], nc + dc[k])) {
			nr += dr[k], nc += dc[k];
			can1[nr][nc] = 1;
		}
	}
	for (int k = 0; k < 6; ++k) {
		int nr = er, nc = ec;
		while (isin(nr + dr[k], nc + dc[k])) {
			nr += dr[k], nc += dc[k];
			can2[nr][nc] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < 21; ++i)
		for (int j = 0; j < 11; ++j)
			ans += can1[i][j] * can2[i][j];
	cout << ans;
}