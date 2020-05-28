// BOJ 1940 주몽
// counting

#include <iostream>
using namespace std;

int cnt[200001];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		if (m - x <= 200000 && m - x >= 0 && cnt[m - x]) {
			ans++;
			cnt[m - x]--;
		}
		else cnt[x]++;
	}
	cout << ans;
}