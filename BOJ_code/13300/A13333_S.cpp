// BOJ 13333 Q-Index
// prefix sum

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, less[10001] = {}, greater[10001] = {};

	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		less[x]++; greater[x]++;
	}

	for (int i = 1; i <= 10000; ++i) less[i] += less[i - 1];
	for (int i = 9999; i >= 0; --i) greater[i] += greater[i + 1];

	for (int i = 0; i < 10000; ++i) {
		if (greater[i] >= i && less[i] >= n - i) {
			cout << i;
			break;
		}
	}
}