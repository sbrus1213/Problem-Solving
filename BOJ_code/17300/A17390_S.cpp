// BOJ 17390 이건 꼭 풀어야 해!
// Prefix sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define BtoE(vec) vec.begin(), vec.end()

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q;
	vector<int> vec;

	cin >> n >> q;
	vec.resize(n + 1);

	for (int i = 1; i <= n; ++i) cin >> vec[i];
	sort(BtoE(vec));

	for (int i = 1; i <= n; ++i) vec[i] = vec[i - 1] + vec[i];

	for (int i = 0; i < q; ++i) {
		int l, r;

		cin >> l >> r;

		cout << vec[r] - vec[l - 1] << '\n';
	}
}