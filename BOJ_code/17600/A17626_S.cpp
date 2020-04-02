// BOJ 17626 Four Squares
// Dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<int> cnt(n + 1);
	cnt[0] = 0; cnt[1] = 1;

	for (int i = 2; i <= n; ++i) {
		cnt[i] = n + 5;
		for (int j = 1; j * j <= i; ++j)
			cnt[i] = min(cnt[i], cnt[i - j * j] + 1);
	}
	cout << cnt[n];
}