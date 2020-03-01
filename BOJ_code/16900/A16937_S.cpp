// BOJ 16937 두 스티커
// Brute force

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int h, w, n, R[101], C[101], res = 0;

	cin >> h >> w >> n;

	for (int i = 0; i < n; ++i) cin >> R[i] >> C[i];

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int tmp = R[i] * C[i] + R[j] * C[j];

			if (R[i] + R[j] <= w && C[i] <= h && C[j] <= h) res = max(res, tmp);

			if (R[i] + C[j] <= w && C[i] <= h && R[j] <= h) res = max(res, tmp);

			if (C[i] + R[j] <= w && R[i] <= h && C[j] <= h) res = max(res, tmp);

			if (C[i] + C[j] <= w && R[i] <= h && R[j] <= h) res = max(res, tmp);

			if (R[i] + R[j] <= h && C[i] <= w && C[j] <= w) res = max(res, tmp);

			if (R[i] + C[j] <= h && C[i] <= w && R[j] <= w) res = max(res, tmp);

			if (C[i] + R[j] <= h && R[i] <= w && C[j] <= w) res = max(res, tmp);

			if (C[i] + C[j] <= h && R[i] <= w && R[j] <= w) res = max(res, tmp);
		}
	}

	cout << res;
}