// BOJ 2775 부녀회장이 될테야
// 조합론

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc, k, n;
	cin >> tc;
	while (tc--) {
		int room[15];
		cin >> k >> n;
		for (int i = 1; i <= n; i++) room[i] = i;
		for (int i = 1; i <= k; i++) {
			for (int j = 2; j <= n; j++) {
				room[j] += room[j - 1];
			}
		}
		cout << room[n] << '\n';
	}
}