// BOJ 17388 와글와글 숭고한

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int s, g, h, m;

	cin >> s >> g >> h;

	if (s + g + h > 99) {
		cout << "OK";
		return 0;
	}

	m = min(s, min(g, h));
	if (s == m) cout << "Soongsil";
	else if (g == m)cout << "Korea";
	else cout << "Hanyang";
}