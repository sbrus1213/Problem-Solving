// BOJ 1312 소수
// 수학

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int a, b, n; cin >> a >> b >> n;
	a %= b;

	for (int i = 1; i < n; ++i)
		a = (a * 10) % b;
	cout << (a * 10) / b;
}