// BOJ 2651 자동차경주대회
// dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int d, n; cin >> d >> n;
	vector<int> dist(n + 2), time(n + 2);
	for (int i = 0; i <= n; ++i) cin >> dist[i];
	for (int i = 1; i <= n; ++i) cin >> time[i];

	vector<pii> dp(n + 2);
	for (int i = 1; i < n + 2; ++i) {
		int dsum = 0;
		pii tmp = dp[i - 1];
		for (int j = i - 1; j >= 0; --j) {
			dsum += dist[j];
			if (dsum > d) break;
			if (dp[j].second < tmp.second) tmp = dp[j];
		}
		dp[i] = pii(tmp.first + 1, tmp.second + time[i]);
	}

	vector<int> ans;
	for (int i = n + 1; i > 0;) {
		int dsum = 0;
		for (int j = i - 1; j >= 0; --j) {
			dsum += dist[j];
			if (dsum > d) break;
			if (dp[j].second == dp[i].second - time[i] && dp[j].first == dp[i].first - 1) {
				ans.push_back(j);
				i = j;
				break;
			}
		}
	}

	cout << dp[n + 1].second << '\n' << dp[n + 1].first - 1 << '\n';
	ans.pop_back();
	reverse(ans.begin(), ans.end());
	for (int a : ans) cout << a << ' ';
}