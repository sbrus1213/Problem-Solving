// BOJ 1722 순열의 순서
// Factorial & Combinatorics

#include <iostream>
#include <vector>
using namespace std;
#define ll	long long

ll facto[21];
void factorial() {
	facto[0] = 1;
	for (int i = 1; i < 21; ++i) {
		facto[i] = facto[i - 1] * i;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	factorial();

	int n, comm;

	cin >> n >> comm;

	if (comm == 1) {
		ll k, tmp;
		vector<int> kth;
		vector<bool> use(n + 1, 0);

		cin >> k;

		for (int i = n - 1; i >= 0; --i) {
			tmp = (k - 1) / facto[i];

			for (int j = 1; j <= n; ++j) {
				if (!use[j]) {
					if (!(tmp--)) {
						use[j] = 1;
						kth.push_back(j);
						break;
					}
				}
			}
			k -= facto[i] * ((k - 1) / facto[i]);
		}

		for (int i = 0; i < n; ++i)
			cout << kth[i] << ' ';
	}
	else {
		ll res = 0, tmp;
		vector<ll> kth(n);
		vector<bool> use(n + 1, 0);

		for (int i = 0; i < n; ++i)
			cin >> kth[i];

		for (int i = 0; i < n; ++i) {
			tmp = 0;

			for (int j = 1; j < kth[i]; ++j) {
				if (!use[j]) ++tmp;
			}

			use[kth[i]] = true;
			res += tmp * facto[n - i - 1];
		}

		cout << res + 1;
	}
}