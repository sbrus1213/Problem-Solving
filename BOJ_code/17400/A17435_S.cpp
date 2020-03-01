// BOJ 17435 합성함수와 쿼리
// Sparse table / dynamic programming ? 

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m;
	cin >> m;

	int table[200001][19];
	for (int i = 1; i <= m; ++i) cin >> table[i][0];

	for (int i = 1; i < 19; ++i)
		for (int j = 1; j <= m; ++j)
			table[j][i] = table[table[j][i - 1]][i - 1];

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n, x;
		cin >> n >> x;
		for (int j = 18; j >= 0; --j)
			if (n >= (1 << j)) {
				x = table[x][j];
				n -= (1 << j);
			}
		cout << x << '\n';
	}
}