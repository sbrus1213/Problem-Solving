// BOJ 2442 별 찍기 - 5
// 구현

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n - i; ++j) cout << ' ';
		for (int j = 0; j < 2 * i - 1; ++j) cout << '*';
		cout << '\n';
	}
}