// BOJ 16561 3ÀÇ ¹è¼ö

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	if (n < 9) cout << 0;
	else {
		n = (n - 9) / 3 + 2;
		cout << n * (n - 1) / 2;
	}
}