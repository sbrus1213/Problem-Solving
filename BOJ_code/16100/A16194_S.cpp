// BOJ 16194 카드 구매하기2
// dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> p, dp;
int go(int i) {
	if (dp[i] != -1) return dp[i];
	int& res = dp[i];
	res = p[i];
	for (int j = i - 1; j > 0; --j)
		res = min(res, go(j) + p[i - j]);
	return res;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	p = vector<int>(n + 1);
	dp = vector<int>(n + 1, -1);
	for (int i = 1; i <= n; ++i)
		cin >> p[i];

	dp[1] = p[1];
	cout << go(n);
}