// BOJ 1735 분수 합
// 수학

#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a > b) swap(a, b);
	while (a) {
		b %= a;
		swap(a, b);
	}
	return b;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2;

	int c = a1 * b2 + a2 * b1, d = b1 * b2;
	int g = gcd(c, d);
	c /= g, d /= g;
	cout << c << ' ' << d;
}