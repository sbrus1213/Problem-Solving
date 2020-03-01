// BOJ Contest Setting
// Dynamic Programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll	long long
#define BtoE(vec) vec.begin(), vec.end()
#define mod 998244353

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	ll dp[1001][1001] = {};
	vector<ll> num, sorted_num, time;

	cin >> n >> k;
	num.resize(n);

	for (int i = 0; i < n; ++i) cin >> num[i];

	sort(BtoE(num));

	sorted_num.push_back(num[0]);
	time.push_back(1);
	for (int i = 1; i < n; ++i) {
		if (num[i] == num[i - 1]) time[time.size() - 1]++;
		else {
			sorted_num.push_back(num[i]);
			time.push_back(1);
		}
	}

	int len = sorted_num.size();

	for (int i = 0; i < len; ++i)
		dp[1][i] = time[i];

	for (int i = 2; i <= k; ++i)
		for (int j = 0; j < len; ++j)
			for (int k = 0; k < j; ++k)
				dp[i][j] = (dp[i][j] + dp[i - 1][k] * time[j]) % mod;

	ll res = 0;
	for (int i = 0; i < len; ++i)
		res = (res + dp[k][i]) % mod;

	cout << res;
}