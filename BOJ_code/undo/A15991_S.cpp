// BOJ 15991 1, 2, 3 더하기 6
// dynamic programming

#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 9;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    vector<int> dp(100100);

    dp[0] = dp[1] = dp[2] = dp[3] = 1;

    for(int i = 0; i <= 100000; i++) {
        dp[i + 2] = (dp[i + 2] + dp[i]) % mod;
        dp[i + 4] = (dp[i + 4] + dp[i]) % mod;
        dp[i + 6] = (dp[i + 6] + dp[i]) % mod;
    }

    int tc; cin >> tc;

    while (tc--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}