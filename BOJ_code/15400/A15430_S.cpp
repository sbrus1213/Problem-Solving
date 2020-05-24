// BOJ 15430 Progressive Scramble
// 구현

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ci(char c) {
	if (c == ' ') return 0;
	return c - 'a' + 1;
}
char ic(int i) {
	if (!i) return ' ';
	return (char)i - 1 + 'a';
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	cin.ignore(1);
	while (tc--) {
		string s; getline(cin, s);
		int len = s.size() - 2, com = s[0] == 'e' ? 1 : 0;
		vector<int> v(len);
		s = s.substr(2);
		if (com) {
			for (int i = 0; i < len; ++i)
				v[i] = ci(s[i]);
			for (int i = 1; i < len; ++i)
				v[i] += v[i - 1];
		}
		else {
			for (int i = 0; i < len; ++i)
				v[i] = ci(s[i]);
			for (int i = 1; i < len; ++i)
				v[i] += i * 27;
			for (int i = len - 1; i > 0; --i)
				v[i] -= v[i - 1];
		}
		for (int i = 0; i < len; ++i)
			v[i] %= 27;
		for (int i = 0; i < len; ++i)
			cout << ic(v[i]);
		cout << '\n';
	}
}