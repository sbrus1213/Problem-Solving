// BOJ 2230 수 고르기
// binary search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, d;
	cin >> n >> d;

	if (n == 1) {
		cout << 0;
		return 0;
	}

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr.begin(), arr.end());

	int ans = arr[n - 1] - arr[0] + 10;
	for (int i = 0; i < n - 1; ++i) {
		int j = upper_bound(arr.begin(), arr.end(), arr[i] + d) - arr.begin();
		if (j == n) continue;
		if (arr[j - 1] == arr[i] + d) j--;
		ans = min(ans, arr[j] - arr[i]);
	}
	cout << ans;
}