// BOJ 2643 색종이 올려 놓기
// Dynamic Programming

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define BtoE(vec) vec.begin(), vec.end()
#define Pii pair<int, int>

int n;
vector<Pii > paper;
int dp[100];

bool isin(Pii curr, Pii above) {
	if (above.first <= curr.first && above.second <= curr.second) return true;
	if (above.second <= curr.first && above.first <= curr.second) return true;
	return false;
}

int dy(int curr) {
	int& res = dp[curr];
	res = 1;

	for (int above = curr + 1; above < n; ++above) {
		if (!isin(paper[curr], paper[above])) continue;

		if (dp[above] == -1) res = max(res, dy(above) + 1);
		else res = max(res, dp[above] + 1);
	}

	return res;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		int w, h;
		cin >> w >> h;
		if (w > h) swap(w, h);
		paper.push_back(Pii(w, h));
	}
	sort(BtoE(paper), greater<Pii >());

	memset(dp, -1, sizeof(dp));

	int res = 0;
	for (int i = n - 1; i >= 0; --i) {
		res = max(res, dy(i));
	}

	cout << res;
}