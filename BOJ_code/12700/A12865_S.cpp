// BOJ 12865 평범한 배낭
// Dynamic Programming - Knapsack

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k, weight[101], value[101], dp[100'001] = {};

	cin >> n >> k;

	for (int i = 0; i < n; ++i) cin >> weight[i] >> value[i];

	/* 1차 - 공간적으로 비효울적인 방법 -
		개선) 바로 이전 단계의 dp값만 보유하면 되므로 그만큼 사이즈를 줄일 수 있음
	int dp[101][100001] = {};

	dp[0][weight[0]] = value[0];
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (j >= weight[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i]] + value[i]);
		}
	}*/
	/* 2차 - 공간을 많이 줄인 방법 - 바로 이전단계만 저장해서 dp 진행 -
		개선) dp[i][j]가 전단계로부터 오는 방법은 j보다 작은 k에 대해 dp[i-1][j] 또는 dp[i-1][k]밖에 없다.
		그러므로 굳이 2차원일 필요도 없이 1차원으로 해서 dp[i][k]부터 dp[i][0] 순서로 채워나가기
		+ 조건문은 필요 없어지며 j 값을 k부터 weight[i] 까지만 체크하면 됨.
	int dp[2][100001] = {};

	dp[0][weight[0]] = value[0];
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dp[i & 1][j] = dp[(i - 1) & 1][j];
			if (j >= weight[i]) dp[i & 1][j] = max(dp[i & 1][j], dp[(i - 1) & 1][j - weight[i]] + value[i]);
		}
	}*/
	dp[weight[0]] = value[0];
	for (int i = 1; i < n; ++i)
		for (int j = k; j >= weight[i]; --j)
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);

	int res = 0;
	for (int i = 0; i <= k; ++i)
		res = max(res, dp[i]);

	cout << res;
}