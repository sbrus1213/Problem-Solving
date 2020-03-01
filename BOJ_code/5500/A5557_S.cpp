// BOJ 5557 1ÇÐ³â
// Dynamic Programming 

#include <iostream>
using namespace std;
#define ll long long

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n, num[100], goal, dp[100][21] = {};

	cin >> n;
	--n;

	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	cin >> goal;

	dp[0][num[0]] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 21; ++j) {

			if (j + num[i] < 21)
				dp[i][j + num[i]] += dp[i - 1][j];

			if (j - num[i] >= 0)
				dp[i][j - num[i]] += dp[i - 1][j];
		}
	}

	cout << dp[n - 1][goal];
}