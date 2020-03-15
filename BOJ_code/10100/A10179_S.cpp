// BOJ 10179 ÄíÆù
// ¼öÇĞ

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		double x; cin >> x;
		cout << fixed;
		cout.precision(2);
		cout << '$' << x * 0.8 << '\n';
	}
}