// BOJ 8714 Monety
// ±¸Çö

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, cnt = 0; cin >> n;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		if (x) cnt++;
	}
	cout << min(cnt, n - cnt);
}