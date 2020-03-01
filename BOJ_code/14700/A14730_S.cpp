// BOJ 14730 ÚºÝÑËÎßãÑº (small)
// ±¸Çö

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, c, k, res = 0;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c >> k;
		res += c * k;
	}
	cout << res;
}