// BOJ 1780 종이의 개수
// D&C

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ne, ze, po, pap[2200][2200];

int dnc(int n, int ii, int jj) {
	if (n == 1) return pap[ii][jj];

	int nn = 0, zz = 0, pp = 0, res;
	n /= 3;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			res = dnc(n, ii + i * n, jj + j * n);
			if (res == 1) pp++;
			else if (res == 0) zz++;
			else if (res == -1) nn++;
		}

	if (pp == 9) return 1;
	else if (zz == 9) return 0;
	else if (nn == 9) return -1;
	else {
		po += pp;
		ze += zz;
		ne += nn;
		return 2;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> pap[i][j];

	int res = dnc(n, 0, 0);
	if (res == 1) po++;
	else if (res == 0) ze++;
	else if (res == -1) ne++;

	cout << ne << ' ' << ze << ' ' << po;
}