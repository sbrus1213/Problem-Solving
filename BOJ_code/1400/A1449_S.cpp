// BOJ 1449 수리공 항승
// greedy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, l; cin >> n >> l;

	vector<int> pos(n);
	for (int i = 0; i < n; ++i)
		cin >> pos[i];
	sort(pos.begin(), pos.end());

	int ans = 0;
	for (int i = 0; i < n;) {
		ans++;
		int p = pos[i];
		while (i < n && pos[i] < p + l) i++;
	}
	cout << ans;
}