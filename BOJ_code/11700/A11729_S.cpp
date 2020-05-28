// BOJ 11729 하노이 탑 이동 순서
// D&C

#include <iostream>
#include <algorithm>
using namespace std;

void hanoi(int n, int a, int b, int c) {
	if (n == 0) return;
	hanoi(n - 1, a, c, b);
	cout << a << ' ' << c << '\n';
	hanoi(n - 1, b, a, c);
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	int ans = 1;
	for (int i = 0; i < n; ++i) ans *= 2;
	cout << --ans << '\n';
	hanoi(n, 1, 2, 3);
}