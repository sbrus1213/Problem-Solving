// BOJ 10250 ACM호텔
// 수학

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc, w, h, n;
	cin >> tc;
	while (tc--) {
		cin >> h >> w >> n;
		cout << ((n % h) ? n % h : h);
		if (n % h)
			if (n / h < 9) cout << 0 << n / h + 1;
			else cout << n / h + 1;
		else
			if (n / h < 10) cout << 0 << n / h;
			else cout << n / h;
		cout << '\n';
	}
}