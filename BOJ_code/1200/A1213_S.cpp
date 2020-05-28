// BOJ 1213 팰린드롬 만들기
// string

#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	string s; cin >> s;

	int alp[26] = {};
	for (char c : s) alp[c - 'A']++;

	int odd = 0;
	for (int i = 0; i < 26; ++i) if (alp[i] % 2 == 1) odd++;
	if (odd > 1) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	char c = ' ';
	for (int i = 0; i < 26; ++i) {
		if (alp[i] % 2 == 1) c = (char)(i + 'A');
		for (int j = 0; j < alp[i] / 2; ++j)
			cout << (char)(i + 'A');
	}
	if (c != ' ') cout << c;
	for (int i = 25; i >= 0; --i) {
		for (int j = 0; j < alp[i] / 2; ++j)
			cout << (char)(i + 'A');
	}
}