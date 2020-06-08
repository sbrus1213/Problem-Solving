// BOJ 17951 흩날리는 시험지 속에서 내 평점이 느껴진거야
// Binary search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;

	vector<int> seq(n);
	for (int i = 0; i < n; ++i) cin >> seq[i];

	int l = 0, r = *max_element(seq.begin(), seq.end()) * n + 1;

	while (l + 1 < r) {
		int mid = (l + r) / 2;

		int c = 0, tmp = 0;
		for (int i = 0; i < n; ++i) {
			tmp += seq[i];
			if (tmp >= mid) {
				c++;
				tmp = 0;
			}
		}

		if (c >= k) l = mid;
		else r = mid;
	}

	cout << l;
}