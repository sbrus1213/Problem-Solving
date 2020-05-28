// BOJ 18114 블랙 프라이데이
// binary search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, c; cin >> n >> c;

	vector<int> w(n);
	for (int& x : w) {
		cin >> x;
		if (x == c) {
			cout << 1;
			return 0;
		}
	}
	sort(w.begin(), w.end());

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (w[i] + w[j] > c) continue;
			else if (w[i] + w[j] == c) {
				cout << 1;
				return 0;
			}
			int sum = w[i] + w[j];
			int idl = lower_bound(w.begin(), w.end(), c - sum) - w.begin();
			int idu = upper_bound(w.begin(), w.end(), c - sum) - w.begin();
			for (int k = idl; k < idu; ++k) {
				if (k != i && k != j) {
					cout << 1;
					return 0;
				}
			}
		}
	}

	cout << 0;
}