// BOJ 2104 부분배열 고르기
// D&C 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

vector<ll> seq;

ll dnc(int l, int r) {
	if (l == r) return seq[l] * seq[l];
	int mid = (l + r) / 2;
	ll ret = max(dnc(l, mid), dnc(mid + 1, r));

	ll mn = seq[mid], sum = seq[mid], li = mid - 1, ri = mid + 1;
	while (l <= li || ri <= r) {
		ll lv = -1, rv = -1;
		if (l <= li) lv = seq[li];
		if (ri <= r) rv = seq[ri];
		if (lv > rv) {
			mn = min(lv, mn);
			sum += lv;
			li--;
		}
		else {
			mn = min(rv, mn);
			sum += rv;
			ri++;
		}
		ret = max(ret, mn * sum);
	}
	return ret;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	seq = vector<ll>(n);
	for (int i = 0; i < n; ++i) cin >> seq[i];

	cout << dnc(0, n - 1);
}