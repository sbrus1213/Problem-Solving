// BOJ 5532 방학 숙제
// 수학

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int l, a, b, c, d; cin >> l >> a >> b >> c >> d;
	a = (!(a % c) ? a / c : a / c + 1);
	b = (!(b % d) ? b / d : b / d + 1);
	cout << l - max(a, b);
}