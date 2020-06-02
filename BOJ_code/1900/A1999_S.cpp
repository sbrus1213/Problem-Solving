// BOJ 1999 최대최소
// memoization

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, b, k; cin >> n >> b >> k;

	int arr[251][251];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> arr[i][j];

	int mx[251][251], mn[251][251];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			mx[i][j] = -1, mn[i][j] = 300;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n - b + 1; ++j) {
			int mxe = -1, mne = 300;
			for (int k = j; k < j + b; ++k) {
				mxe = max(mxe, arr[i][k]);
				mne = min(mne, arr[i][k]);
			}
			mx[i][j] = mxe;
			mn[i][j] = mne;
		}
	}
	for (int j = 1; j <= n - b + 1; ++j) {
		for (int i = 1; i <= n - b + 1; ++i) {
			int mxe = -1, mne = 300;
			for (int k = i; k < i + b; ++k) {
				mxe = max(mxe, mx[k][j]);
				mne = min(mne, mn[k][j]);
			}
			mx[i][j] = mxe;
			mn[i][j] = mne;
		}
	}

	for (int i = 0; i < k; ++i) {
		int r, c; cin >> r >> c;
		cout << mx[r][c] - mn[r][c] << '\n';
	}
}