// BOJ 2921 도미노
// 수학

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	int ans = 0;
	for (int i = 0; i <= n; ++i)
		ans += (n + i) * (n - i + 1) / 2 + i * (n - i + 1);
	cout << ans;
}