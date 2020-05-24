// BOJ 15429 Odd Gnome
// Brute force

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;

		vector<int> seq(n + 1);
		for (int i = 1; i <= n; ++i) cin >> seq[i];
		for (int j = 2; j < n; ++j) {
			bool fl = true;
			int prv = -1;
			for (int i = 1; i <= n; ++i) {
				if (i == j) continue;
				if (seq[i] < prv) {
					fl = false;
					break;
				}
				prv = seq[i];
			}
			if (fl) {
				cout << j << '\n';
				break;
			}
		}
	}
}