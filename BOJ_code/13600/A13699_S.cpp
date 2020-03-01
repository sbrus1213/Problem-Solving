// BOJ 13699 Á¡È­½Ä
// Dynamic Programming

#include <iostream>
using namespace std;
#define ll	long long

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n, dp[36] = { 1 };

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i] += dp[j] * dp[i - 1 - j];
		}
	}

	cout << dp[n];
}