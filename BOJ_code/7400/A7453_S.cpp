// BOJ 7453 합이 0인 네 정수
// Binary search / Two pointer

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll	long long
#define BtoE(vec) vec.begin(), vec.end()

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n, res = 0;

	cin >> n;
	vector<int> a(n), b(n), c(n), d(n), ab(n * n), cd;

	for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i] >> d[i];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ab[(i * n) + j] = a[i] + b[j];
	sort(BtoE(ab));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			res += lower_bound(BtoE(ab), -(c[i] + d[j]) + 1) - lower_bound(BtoE(ab), -(c[i] + d[j]));

	cout << res;

	/*

	ll n, res = 0;

	cin >> n;
	vector<int> a(n), b(n), c(n), d(n), ab(n * n), cd(n*n);

	for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i] >> d[i];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ab[(i * n) + j] = a[i] + b[j];
			cd[(i * n) + j] = c[i] + d[j];
		}
	}

	sort(BtoE(ab));
	sort(BtoE(cd), greater<int>());

	for (ll i = 0, j = 0; i < n * n && j < n * n; ) {
		if (ab[i] + cd[j] < 0)
			++i;
		else if (ab[i] + cd[j] > 0)
			++j;
		else {
			ll ti = i, tj = j;
			while (ti + 1 < n * n && ab[ti] == ab[ti + 1])
				++ti;
			while (tj + 1 < n * n && cd[tj] == cd[tj + 1])
				++tj;

			res += (ti - i + 1) * (tj - j + 1);
			i = ti + 1, j = tj + 1;
		}
	}

	cout << res;
	*/
}