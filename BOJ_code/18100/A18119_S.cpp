// BOJ 18119 단어 암기
// bitmask

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vector<int> alp(n);
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		int t = 0;
		for (char c : s) {
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') continue;
			t |= (1 << (c - 'a'));
		}
		alp[i] = t;
	}

	int bit = (1 << 26) - 1;
	for (int i = 0; i < m; ++i) {
		int o; char x; cin >> o >> x;
		bit ^= (1 << (x - 'a'));

		int c = 0;
		for (int y : alp)
			if ((bit & y) == y) c++;

		cout << c << '\n';
	}
}