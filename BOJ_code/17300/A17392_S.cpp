// BOJ 17392 우울한 방학
// 구현

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, sum = 0;

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		int x;

		cin >> x;

		sum += (x + 1);
	}

	int res = 0;
	if (sum < m) {
		m -= sum;

		int p = ((m - 1) / (n + 1)) + 1, q = ((m - 1) % (n + 1)) + 1;
		res += (p * (p + 1) * ((2 * p) + 1)) * q / 6 + (p * (p - 1) * ((2 * p) - 1)) * (n + 1 - q) / 6;
	}

	cout << res;
}