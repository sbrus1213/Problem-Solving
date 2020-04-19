// BOJ 1725 히스토그램
// D&C 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> hgt;

int dnc(int l, int r) {
	if (l == r) return hgt[l];
	int mid = (l + r) / 2;
	int ret = max(dnc(l, mid), dnc(mid + 1, r));

	int h = hgt[mid], w = 1, li = mid - 1, ri = mid + 1;
	while (l <= li || ri <= r) {
		int lh = -1, rh = -1;
		if (l <= li) lh = min(hgt[li], h);
		if (ri <= r) rh = min(hgt[ri], h);
		if (lh > rh) {
			h = min(lh, h);
			li--;
		}
		else {
			h = min(rh, h);
			ri++;
		}
		ret = max(ret, h * (++w));
	}
	return ret;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	hgt = vector<int>(n);
	for (int i = 0; i < n; ++i) cin >> hgt[i];

	cout << dnc(0, n - 1);
}