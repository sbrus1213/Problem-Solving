// BOJ 2438 별 찍기 - 1
// 구현

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) cout << "*";
		cout << "\n";
	}
}