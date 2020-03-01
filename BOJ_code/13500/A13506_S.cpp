// BOJ 13506 카멜레온 부분 문자열
// string search - z algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mxn = 1e6 + 1;

int cnt[mxn];
bool flag[mxn];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;

	int sz = s.size(), l = 0, r = 0;
	vector<int> z(sz);
	for (int i = 1; i < sz; ++i) {
		if (i <= r) z[i] = min(z[i - l], r - i + 1);
		while (i + z[i] < sz && s[z[i]] == s[z[i] + i]) z[i]++;
		if (r < i + z[i] - 1) l = i, r = i + z[i] - 1;
	}

	for (int i = 1; i < sz; ++i) {
		if (!z[i]) continue;
		cnt[z[i]]++;
		if (i + z[i] == sz) flag[z[i]] = true;
	}
	for (int i = sz - 1; i > 0; --i) {
		if (cnt[i] >= 2 && flag[i]) {
			for (int j = 0; j < i; ++j)
				cout << s[j];
			return 0;
		}
		cnt[i - 1] += cnt[i];
	}
	cout << -1;
}