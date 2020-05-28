// BOJ 2470 두 용액
// Two pointer

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> po, ne;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		if (x >= 0) po.push_back(x);
		else if (x < 0) ne.push_back(x);
	}
	sort(po.begin(), po.end());
	sort(ne.rbegin(), ne.rend());

	int mn = 2e9 + 3, mnx, mny;
	if (po.size() > 1 && mn > po[0] + po[1]) {
		mn = po[0] + po[1];
		mnx = po[0];
		mny = po[1];
	}
	if (ne.size() > 1 && mn > (abs(ne[0] + ne[1]))) {
		mn = abs(ne[0] + ne[1]);
		mnx = ne[1];
		mny = ne[0];
	}

	int pi = 0, ni = 0;
	while (1) {
		if (pi == po.size() || ni == ne.size()) break;
		if (mn > abs(po[pi] + ne[ni])) {
			mn = abs(po[pi] + ne[ni]);
			mnx = ne[ni];
			mny = po[pi];
		}
		if (po[pi] + ne[ni] > 0) ni++;
		else if (po[pi] + ne[ni] < 0) pi++;
		else break;
	}
	cout << mnx << ' ' << mny;
}