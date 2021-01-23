// BOJ 17009 Winning Score
// 시뮬레이션

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int a = 0, b = 0;
	for (int i = 3; i; i--) {
		int x; cin >> x;
		a += i * x;
	}
	for (int i = 3; i; i--) {
		int x; cin >> x;
		b += i * x;
	}
	if (a == b) cout << "T";
	else if (a > b) cout << "A";
	else cout << "B";

	return 0;
}