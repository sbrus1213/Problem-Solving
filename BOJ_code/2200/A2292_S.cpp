// BOJ 2292 ¹úÁý
// ¼öÇÐ

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n, i, j;
	cin >> n;
	for (i = 1, j = 1; ; i++) {
		if (n <= j) break;
		j += 6 * i;
	}
	cout << i;
}