// BOJ 10871 X보다 작은 수
// 수학

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int a, b; cin >> a >> b;
	for (int i = 0; i < a; ++i) {
		int x; cin >> x;
		if (x < b) cout << x << ' ';
	}
}