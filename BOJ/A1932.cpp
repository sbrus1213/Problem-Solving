// BOJ 1932 Á¤¼ö »ï°¢Çü
// Dynaic Programming

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <set>
#include <tuple>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;
#define ll	long long
#define BtoE(vec) vec.begin(), vec.end()
#define Pii pair<int, int>
#define Psi pair<string, int>
#define Tii tuple<int, int, int>

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	int n, i, j, res = 0;
	vector<vector<int> > triangle, dp;

	cin >> n;
	triangle.resize(n);
	dp.resize(n);

	for (i = 0; i < n; ++i) {
		triangle[i].resize(i + 1);
		dp[i].resize(i + 1);

		for (j = 0; j <= i; ++j)
			cin >> triangle[i][j];
	}

	dp[0] = triangle[0];
	for (i = 1; i < n; ++i) {

		dp[i][0] = dp[i - 1][0] + triangle[i][0];
		dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];

		for (j = 1; j < i; ++j) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
		}
	}

	for (i = 0; i < n; ++i) {
		res = max(res, dp[n - 1][i]);
	}

	cout << res;
}