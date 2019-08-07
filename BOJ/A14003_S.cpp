// BOJ 14003 가장 긴 증가하는 부분 수열 5
// Dynamic Programming - LIS(Lower bound) & Binary Search

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll	long long
#define BtoE(vec) vec.begin(), vec.end()
#define Pii pair<int, int>
#define Psi pair<string, int>
#define Tii tuple<int, int, int>

int seq[1'000'001], dp[1'000'001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, idx;
	vector<int> lis;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> seq[i];

		if (lis.empty() || lis.back() < seq[i]) {
			lis.push_back(seq[i]);
			dp[i] = lis.size();

			idx = i;
		}
		else {
			int tmp = lower_bound(BtoE(lis), seq[i]) - lis.begin();

			lis[tmp] = seq[i];
			dp[i] = tmp + 1;
		}
	}

	int res = lis.size();
	vector<int> ans;

	ans.push_back(seq[idx]);
	for (int i = idx - 1; i >= 0; --i) {
		if (seq[i] < seq[idx] && dp[i] == dp[idx] - 1) {
			ans.push_back(seq[i]);
			idx = i;
		}
	}

	cout << res << '\n';
	for (int i = 0; i < res; ++i)
		cout << ans[res - 1 - i] << ' ';
}