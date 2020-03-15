// BOJ 16430 제리와 톰
// 수학

#include <iostream>
using namespace std;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b; cin >> a >> b; a = b - a;
	for (int i = 2; i <= 9; ++i)
		if (!(a % i) && !(b % i))
			a /= i, b /= i;

	cout << a << ' ' << b;
}