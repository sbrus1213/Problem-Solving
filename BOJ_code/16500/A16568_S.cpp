// BOJ 16568 엔비스카의 영혼
// Dynamic Programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a, b;
	vector<int> cnt;

	cin >> n >> a >> b;
	cnt.resize(n + 1, -1);
	cnt[0] = 0;

	for (int i = 1; i <= n; ++i) {
		cnt[i] = cnt[i - 1] + 1;
		if (i > a) cnt[i] = min(cnt[i], cnt[i - a - 1] + 1);
		if (i > b) cnt[i] = min(cnt[i], cnt[i - b - 1] + 1);
	}
	cout << cnt[n];
}