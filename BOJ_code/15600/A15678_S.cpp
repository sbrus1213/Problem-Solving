// BOJ 15678 연세 워터파크
// dynamic programming - deque

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, d;
	cin >> n >> d;

	vector<ll> score(n), dp(n);
	for (int i = 0; i < n; ++i) {
		cin >> score[i];
		dp[i] = score[i];
	}

	deque<int> dq;
	dq.push_back(0);
	for (int i = 1; i < n; ++i) {
		while (!dq.empty() && i - dq.front() > d) dq.pop_front();
		dp[i] = max(dp[i], dp[dq.front()] + dp[i]);
		while (!dq.empty() && dp[dq.back()] < dp[i]) dq.pop_back();
		dq.push_back(i);
	}

	ll ans = (-1e9 - 7) * n;
	for (int i = 0; i < n; ++i) ans = max(ans, dp[i]);
	cout << ans;
}