// BOJ 3078 좋은 친구
// Sliding window

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<int> name(n);
	int cnt[21] = {};
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		name[i] = s.size();
	}

	long long ans = 0;
	for (int i = 0; i < min(n, k + 1); ++i)
		ans += cnt[name[i]]++;
	for (int i = k + 1, j = 0; i < n; ++i, ++j) {
		cnt[name[j]]--;
		ans += cnt[name[i]]++;
	}
	cout << ans;
}