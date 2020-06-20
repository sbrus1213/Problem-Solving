// BOJ 8394 악수
// dynamic programming

#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;
	
	if (n < 4) {
		cout << n;
		return 0;
	}

	int a = 2, b = 3;
	for (int i = 4; i <= n; ++i) {
		int t = b;
		b = (a + b) % 10;
		a = t;
	}
	cout << b;
}