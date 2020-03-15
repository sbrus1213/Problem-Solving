// BOJ 5893 17배
// 구현 수학

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s; cin >> s; reverse(s.begin(), s.end());
	int t[2000] = {};
	for (int i = 0; i < s.size(); ++i) {
		t[i] += (s[i] - '0');
		t[i + 4] += (s[i] - '0');
	}
	for (int i = 0; i < 2000; ++i)
		if (t[i] > 1) {
			t[i + 1] += t[i] / 2;
			t[i] = t[i] % 2;
		}
	int idx;
	for (int i = 0; i < 2000; ++i) if (t[i] == 1) idx = i;
	for (int i = idx; i >= 0; --i) cout << t[i];
}