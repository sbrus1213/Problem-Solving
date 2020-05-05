// BOJ 10986 나머지 합
// prefix sum

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;

	long long cnt[1001] = { 1, }, s = 0;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x; s = (s + x) % k;
		cnt[s]++;
	}

	long long ans = 0;
	for (int i = 0; i < k; ++i)
		ans += (cnt[i] * (cnt[i] - 1)) / 2;
	cout << ans;
}
