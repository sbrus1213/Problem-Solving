// BOJ 1436 ¿µÈ­°¨µ¿ ¼ò
// Search

#include <iostream>
using namespace std;

bool is(int n) {
	while (n > 100) {
		if (n % 1000 == 666) return true;
		n /= 10;
	}
	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, ans; cin >> n;
	for (int i = 666, cnt = 0; cnt < n; ++i)
		if (is(i)) cnt += 1, ans = i;
	cout << ans;
}