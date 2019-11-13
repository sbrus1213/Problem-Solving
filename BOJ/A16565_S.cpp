// BOJ 16565 NÆ÷Ä¿
// Dynamic programming

#include <iostream>
using namespace std;
#define mod 10007

int n, bino[53][53];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int res = 0;

	for (int i = 0; i <= 52; ++i) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			bino[i][j] = (bino[i - 1][j - 1] + bino[i - 1][j]) % mod;
		}
	}

	cin >> n;
	for (int i = 4; i <= n; i += 4) {
		res = (res + ((i / 4) % 2 ? 1 : -1) * bino[13][i / 4] * bino[52 - i][n - i]) % mod;
	}
	if (res < 0) res += mod;

	cout << res;
}