// BOJ 14170 Counting Haybales
// binary search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q; cin >> n >> q;

	vector<int> hb(n);
	for (int i = 0; i < n; ++i) cin >> hb[i];
	sort(hb.begin(), hb.end());

	for (int i = 0; i < q; ++i) {
		int l, r; cin >> l >> r;
		int cnt = upper_bound(hb.begin(), hb.end(), r) - lower_bound(hb.begin(), hb.end(), l);
		cout << cnt << '\n';
	}
}