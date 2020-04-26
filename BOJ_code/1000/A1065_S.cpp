// BOJ 1065 ÇÑ¼ö
// Brute force

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	int cnt = 0;
	for (int i = 1; i <= min(n, 999); ++i) {
		if (i < 100) cnt++;
		else {
			int a = (i / 10) % 10 - i % 10;
			int b = (i / 100) % 10 - (i / 10) % 10;
			if (a == b) cnt++;
		}
	}
	cout << cnt;
}