// BOJ 16408 Poker Hand

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int alp[26], cnt[13] = {};
	alp['A' - 'A'] = 0;
	alp['T' - 'A'] = 9;
	alp['J' - 'A'] = 10;
	alp['Q' - 'A'] = 11;
	alp['K' - 'A'] = 12;

	string s;

	for (int i = 0; i < 5; ++i) {
		cin >> s;

		if (s[0] <= '9') cnt[s[0] - '0' - 1]++;
		else cnt[alp[s[0] - 'A']]++;
	}

	int res = 0;
	for (int i = 0; i < 13; ++i) res = max(res, cnt[i]);

	cout << res;
}