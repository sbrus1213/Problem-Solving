// BOJ 16468 크리스마스 트리 꾸미기
// DP tree

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;
const ll mod = 100030001;

ll dp[303][303];

ll go(int n, int l) {
	if (dp[n][l] != -1) return dp[n][l];
	if (!n) return dp[n][l] = 1;
	if (!l) return dp[n][l] = 0;

	ll &res = dp[n][l] = 0;

	n--;
	for (int left = 0; left <= n; left++) {
		int right = n - left;
		res = (res + go(left, l - 1) * go(right, l - 1)) % mod;
	}

	return res;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, l; cin >> n >> l;

	memset(dp, -1, sizeof dp);
	cout << (go(n, l) - go(n, l - 1) + mod) % mod;

	return 0;
}