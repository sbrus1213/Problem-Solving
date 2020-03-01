// BOJ 2011 암호코드
// Dynamic Programming

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define div 1'000'000

int dp[5001], l;
string crypto;

int dynamic(int idx) {
	if (idx == l) return dp[idx] = 1;
	if (crypto[idx] == '0') return dp[idx] = 0;

	if (dp[idx + 1] == -1) dp[idx] = dynamic(idx + 1);
	else dp[idx] = dp[idx + 1];

	char tmp = crypto[idx];
	if (idx + 1 != l && (tmp == '1' || (tmp == '2' && crypto[idx + 1] <= '6'))) {
		if (dp[idx + 2] == -1) dp[idx] += dynamic(idx + 2);
		else dp[idx] += dp[idx + 2];
	}

	return dp[idx] = dp[idx] % div;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> crypto;
	l = crypto.size();

	memset(dp, -1, sizeof(dp));

	cout << dynamic(0);
}