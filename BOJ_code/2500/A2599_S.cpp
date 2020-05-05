// BOJ 2599 짝 정하기
// 수학

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	bool fl = true;
	if (a > d + f) fl = false;
	if (c > b + f) fl = false;
	if (e > b + d) fl = false;

	if (fl) {
		cout << 1 << '\n';
		if (a > f) {
			cout << a - f << ' ' << f << '\n';
			d -= (a - f); f = 0;
		}
		else {
			cout << 0 << ' ' << f - a << '\n';
			f -= a;
		}
		cout << c - f << ' ' << f << '\n';
		b -= (c - f);
		cout << b << ' ' << d;
	}
	else cout << 0;
}