// BOJ 16066 Expired License
// greatest common divisor & Eratosthenes sieve

#include <iostream>
#include <string>

using namespace std;

bool check[10000000];

void era() {
	for (int i = 2; i < 10000000; ++i)
		for (int j = 2; i * j < 10000000; ++j)
			check[i * j] = true;
}

int gcd_find(int a, int b) {
	while (a) {
		if (a < b) swap(a, b);
		a = a % b;
	}
	return b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(check, false, sizeof(check));
	check[1] = true;
	era();

	int tc;

	cin >> tc;

	while (tc--) {
		string a, b;

		cin >> a >> b;

		a += 'x';
		b += 'x';

		int aa = 0, bb = 0, cnt;
		bool flag = false;

		cnt = 0;
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] == '.') flag = true;
			if (a[i] == 'x') break;
			if (a[i] != '.') {
				aa = aa * 10 + a[i] - '0';
				if (flag) cnt++;
			}
		}
		for (int i = cnt; i < 5; ++i)aa = aa * 10;

		cnt = 0; flag = false;
		for (int i = 0; i < b.size(); ++i) {
			if (b[i] == '.') flag = true;
			if (b[i] == 'x') break;
			if (b[i] != '.') {
				bb = bb * 10 + b[i] - '0';
				if (flag) cnt++;
			}
		}
		for (int i = cnt; i < 5; ++i)bb = bb * 10;

		if (aa == bb) cout << "2 2\n";
		else {
			int _gcd = gcd_find(aa, bb);
			aa /= _gcd; bb /= _gcd;

			if (!check[aa] && !check[bb]) cout << aa << ' ' << bb << '\n';
			else cout << "impossible\n";
		}
	}
}