// BOJ 10816 숫자 카드 2
// binary search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<int> ca(n);
	for (int i = 0; i < n; ++i) cin >> ca[i];
	sort(ca.begin(), ca.end());

	int m; cin >> m;
	for (int i = 0; i < m; ++i) {
		int x; cin >> x;
		cout << upper_bound(ca.begin(), ca.end(), x) - lower_bound(ca.begin(), ca.end(), x) << ' ';
	}
}