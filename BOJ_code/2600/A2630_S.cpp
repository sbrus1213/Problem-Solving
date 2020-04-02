// BOJ 2630 색종이 만들기
// D&C

#include <iostream>
using namespace std;
using pii = pair<int, int>;

int w, b, pap[200][200];

int dnc(int n, int i, int j) {
	if (n == 1) return pap[i][j];

	int ww = 0, bb = 0, t, di[] = { 0, n / 2, 0, n / 2 }, dj[] = { 0, 0, n / 2, n / 2 };
	for (int k = 0; k < 4; ++k) {
		t = dnc(n / 2, i + di[k], j + dj[k]);
		if (t == 1) bb++;
		else if (!t) ww++;
	}

	if (bb == 4) return 1;
	if (ww == 4) return 0;
	b += bb;
	w += ww;
	return 2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> pap[i][j];
	int res = dnc(n, 0, 0);
	if (res == 1) b++;
	else if (!res) w++;
	cout << w << '\n' << b;
}