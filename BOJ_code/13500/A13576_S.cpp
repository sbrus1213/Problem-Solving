// BOJ 13576 Prefix¿Í Suffix
// string search - z algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mxn = 1e5 + 1;

int cnt[mxn];
bool flag[mxn];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;

	int sz = s.size(), l = 0, r = 0, cc = 1;
	vector<int> z(sz);
	z[0] = sz; flag[sz] = true;
	for (int i = 1; i < sz; ++i) {
		if (i <= r) z[i] = min(z[i - l], r - i + 1);
		while (i + z[i] < sz && s[z[i]] == s[z[i] + i]) z[i]++;
		if (r < i + z[i] - 1) l = i, r = i + z[i] - 1;
		if (i + z[i] == sz) {
			flag[z[i]] = true;
			cc++;
		}
	}

	for (int i = 0; i < sz; ++i) {
		if (!z[i]) continue;
		cnt[z[i]]++;
	}
	for (int i = sz; i > 0; --i)
		cnt[i - 1] += cnt[i];

	cout << cc << '\n';
	for (int i = 1; i <= sz; ++i)
		if (flag[i]) cout << i << ' ' << cnt[i] << '\n';
}