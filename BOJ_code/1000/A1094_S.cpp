// BOJ 1094 막대기
// 수학

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	int ans = 0;
	while (n) {
		if (n % 2) ans++;
		n /= 2;
	}
	cout << ans;
}