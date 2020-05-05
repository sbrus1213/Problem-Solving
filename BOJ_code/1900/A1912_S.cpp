// BOJ 1912 연속합
// Dynamic Programming

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;

	int res = -1e9, dp = 0;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		if (dp < 0) dp = x;
		else dp += x;
		res = max(res, dp);
	}

	cout << res;
}