// BOJ 2475 검증수
// 구현

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x, s = 0;
	for (int i = 0; i < 5; i++) cin >> x, s += (x * x);
	cout << s % 10;
}