// BOJ 11050 이항 계수 1
// Combinatorics

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k, res = 1;

	cin >> n >> k;

	for (int i = 0; i < k; ++i)
		res *= n - i;

	for (int i = 0; i < k; ++i)
		res /= (i + 1);

	cout << res;
}