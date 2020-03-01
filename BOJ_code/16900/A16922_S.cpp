// BOJ 16922 로마 숫자 만들기 2
// Brute force

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	bool check[1001];

	cin >> n;

	memset(check, false, sizeof(check));
	for (int i = 0; i <= n; ++i) {
		for (int v = 0; v <= n - i; ++v) {
			for (int x = 0; x <= n - v - i; ++x) {
				int l = n - x - v - i;
				check[i + (v * 5) + (x * 10) + (l * 50)] = true;
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= 1000; ++i) if (check[i]) ++res;

	cout << res;
}
