// BOJ 2577 숫자의 개수
// 구현

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, res, ans[10] = {};
	cin >> a >> b >> c;
	res = a * b * c;
	while (res) {
		ans[res % 10]++;
		res /= 10;
	}
	for (int i = 0; i < 10; ++i)cout << ans[i] << '\n';
}