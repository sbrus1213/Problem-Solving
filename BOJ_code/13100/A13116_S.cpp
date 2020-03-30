// BOJ 13116 30¹ø
// ¼öÇÐ

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int a, b; cin >> a >> b;
		while (a != b) {
			if (a < b) b /= 2;
			else a /= 2;
		}
		cout << a * 10 << '\n';
	}
}