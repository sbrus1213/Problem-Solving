// BOJ 1629 °ö¼À
// Divide & Conquer

#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll a, b, c, res = 1;
	cin >> a >> b >> c;
	while (b) {
		if (b % 2) {
			res = (res * a) % c;
		}
		b /= 2;
		a = (a * a) % c;
	}
	cout << res;
}