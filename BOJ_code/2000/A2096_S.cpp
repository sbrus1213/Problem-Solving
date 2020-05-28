// BOJ 2096 내려가기
// dynamic programming & sliding window

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	int mxdp[2][5] = {}, mndp[2][5] = {};

	for (int i = 1; i <= 3; ++i) {
		cin >> mxdp[1][i];
		mndp[1][i] = mxdp[1][i];
	}
	mndp[0][0] = mndp[0][4] = mndp[1][0] = mndp[1][4] = 1e7;

	for (int i = 1; i < n; ++i) {
		int cur = (i + 1) % 2, prv = i % 2;
		for (int j = 1; j <= 3; ++j) {
			int x; cin >> x;
			mxdp[cur][j] = max({ mxdp[prv][j - 1], mxdp[prv][j], mxdp[prv][j + 1] }) + x;
			mndp[cur][j] = min({ mndp[prv][j - 1], mndp[prv][j], mndp[prv][j + 1] }) + x;
		}
	}

	cout << max({ mxdp[n % 2][1], mxdp[n % 2][2], mxdp[n % 2][3] }) << ' ';
	cout << min({ mndp[n % 2][1], mndp[n % 2][2], mndp[n % 2][3] });
}