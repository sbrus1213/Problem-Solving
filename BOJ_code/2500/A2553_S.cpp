// BOJ 2533 마지막 팩토리얼 수
// 수학

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n, ans = 1; cin >> n;
	for (int i = 2; i <= n; ++i) {
		ans = ans * i;
		while (!(ans % 10)) ans /= 10;
		ans %= 1000000;
	}
	cout << ans % 10;
}