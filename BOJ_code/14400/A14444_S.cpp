// BOJ 14444 가장 긴 팰린드롬 부분 문자열
// manacher algorithm

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s, ss; cin >> s;
	int len = s.size();
	for (int i = 0; i <= 2 * len; ++i)
		if (i % 2) ss += s[i / 2];
		else ss += '0';

	int p = 0, r = 0;
	vector<int> l(2 * len + 1);
	for (int i = 0; i <= 2 * len; ++i) {
		if (i <= r) l[i] = min(r - i, l[2 * p - i]);
		while (i - l[i] - 1 >= 0 && i + l[i] + 1 <= 2 * len && ss[i - l[i] - 1] == ss[i + l[i] + 1])
			l[i]++;
		if (i + l[i] > r) {
			p = i; r = i + l[i];
		}
	}

	int ans = -1;
	for (int i = 0; i <= 2 * len; ++i)
		ans = max(ans, l[i]);
	cout << ans;
}