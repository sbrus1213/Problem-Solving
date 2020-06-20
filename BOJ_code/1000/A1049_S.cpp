// BOJ 1049 기타줄
// Greedy

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	int six = 100000, one = 100000;
	for (int i = 0; i < m; ++i) {
		int s, o; cin >> s >> o;
		six = min(six, s);
		one = min(one, o);
	}

	int c = (n % 6 ? n / 6 + 1 : n / 6), ans = six * c;
	for (int i = 0; i < c; ++i) {
		int t = six * i + one * (n - 6 * i);
		ans = min(ans, t);
	}
	cout << ans;
}