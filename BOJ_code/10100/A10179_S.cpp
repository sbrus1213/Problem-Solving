// BOJ 10179 쿠폰
// 수학

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		double p; cin >> p;
		cout << fixed;
		cout.precision(2);
		cout << '$' << p * 0.8 << '\n';
	}
}