// BOJ 16570 앞뒤가 맞는 수열
// KMP - fail function

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, ans = 0, cnt = 0;
	vector<int> num, fail;

	cin >> n;
	num.resize(n);
	fail.resize(n);

	for (int i = n - 1; i >= 0; i--) cin >> num[i];

	for (int i = 1, j = 0; i < n; ++i) {
		while (num[i] != num[j]) {
			if (!j) break;
			j = fail[j - 1];
		}
		if (num[i] == num[j]) fail[i] = ++j;
		ans = max(ans, fail[i]);
	}

	for (int i = 0; i < n; ++i)  if (fail[i] == ans) cnt++;

	if (!ans) cout << -1;
	else cout << ans << ' ' << cnt;
}