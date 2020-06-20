// BOJ 방 배정하기
// dynamic programming

#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int a, b, c, n; cin >> a >> b >> c >> n;

	vector<int> can(n + 1);
	can[0] = 1;
	for (int i = 0; i <= n; ++i) {
		if (i + a <= n) can[i + a] |= can[i];
		if (i + b <= n) can[i + b] |= can[i];
		if (i + c <= n) can[i + c] |= can[i];
	}
	cout << can[n];
}