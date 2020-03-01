// BOJ 16649 Building a star
// ±¸Çö

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;

	if (n == 2) cout << -1;
	else {
		cout << (n + 1) / 2 << '\n';
		for (int i = 0; i < (n - 1) / 2; ++i) {
			cout << 'o';
			if (i == (n - 1) / 2 - 1) {
				if (n % 2) for (int j = 0; j < (n - 1) / 2; ++j) cout << '.';
				else {
					cout << 'o';
					for (int j = 1; j < (n - 1) / 2; ++j) cout << '.';
				}
			}
			else for (int j = 0; j < (n - 1) / 2; ++j)cout << '.';
			cout << '\n';
		}
		for (int i = 0; i < (n + 1) / 2; ++i) cout << 'o';
	}
}