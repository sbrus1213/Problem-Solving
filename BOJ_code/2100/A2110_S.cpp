// BOJ 2110 공유기 설치
// Binary search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;

	vector<int> pos(n);
	for (int i = 0; i < n; ++i) cin >> pos[i];
	sort(pos.begin(), pos.end());

	int low = 1, high = pos[n - 1] - pos[0];
	while (low + 1 < high) {
		int mid = (low + high) / 2, cnt = 1, prv = 0;
		for (int i = 1; i < n; ++i) {
			if (pos[i] - pos[prv] >= mid) {
				cnt++;
				prv = i;
			}
		}
		if (cnt < k) high = mid;
		else low = mid;
	}

	cout << low;
}