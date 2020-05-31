// BOJ 16395 파스칼의 삼각형
// dynamic programming

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k; n--; k--;

	long long ans = 1;
	k = max(k, n - k);
	for (int i = n; i > k; --i) ans *= i;
	for (int i = n - k; i > 0; --i) ans /= i;
	cout << ans;
}