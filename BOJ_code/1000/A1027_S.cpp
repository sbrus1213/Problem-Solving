// BOJ 1027 고층건물
// 수학

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, h[51], cnt[51] = {}; cin >> n;
	for (int i = 0; i < n; ++i) cin >> h[i];

	for (int i = 0; i < n; ++i) {
		double mxh = h[i];
		for (int j = i - 1; j >= 0; --j) {
			if (mxh > (double)(h[i] - h[j]) / (i - j)) {
				cnt[i]++;
				mxh = (double)(h[i] - h[j]) / (i - j);
			}
		}
		mxh = -h[i];
		for (int j = i + 1; j < n; ++j) {
			if (mxh < (double)(h[j] - h[i]) / (j - i)) {
				cnt[i]++;
				mxh = (double)(h[j] - h[i]) / (j - i);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) ans = max(ans, cnt[i]);
	cout << ans;
}