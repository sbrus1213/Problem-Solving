// BOJ 11049 Çà·Ä °ö¼À ¼ø¼­
// Dynamic Programming

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll	long long
#define INF (1e9+7)

struct matrix {
	ll r, c;
};

ll n, dp[501][501];
matrix mat[501];

void dynamic(int i, int j) {
	if (i == j) {
		dp[i][j] = 0;
		return;
	}

	ll _min = INF;
	for (int k = i; k < j; ++k) {
		if (dp[i][k] == -1) dynamic(i, k);
		if (dp[k + 1][j] == -1) dynamic(k + 1, j);

		_min = min(_min, dp[i][k] + dp[k + 1][j] + mat[i].r * mat[k].c * mat[j].c);
	}

	dp[i][j] = _min;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		ll r, c;

		cin >> r >> c;

		mat[i] = { r, c };
	}

	memset(dp, -1, sizeof(dp));
	dynamic(0, n - 1);

	cout << dp[0][n - 1];
}