// BOJ 10982 青款捻虐 力累家
// Dynamic programming - knapsack

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		vector<int> A(n), B(n);
		int A_tot = 0;
		for (int i = 0; i < n; ++i) {
			cin >> A[i] >> B[i];
			A_tot += A[i];
		}

		vector<int> dp(A_tot + 1, INF);
		dp[0] = B[0]; dp[A[0]] = 0;
		for (int i = 1; i < n; ++i)
			for (int j = A_tot; j >= 0; --j)
				if (j >= A[i]) dp[j] = min(dp[j] + B[i], dp[j - A[i]]);
				else dp[j] = dp[j] + B[i];

		int res = INF;
		for (int i = 0; i <= A_tot; ++i)
			res = min(res, max(i, dp[i]));
		cout << res << '\n';
	}
}