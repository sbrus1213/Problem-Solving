// BOJ 17954 투튜브
// Greedy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	if (n == 1) {
		cout << 2 << '\n' << 1 << '\n' << 2;
		return 0;
	}

	vector<int> seq;
	for (int i = 2 * n - 3; i >= n - 1; --i) seq.push_back(i);
	seq.push_back(2 * n - 2);
	seq.push_back(2 * n - 1);
	for (int i = n - 2; i > 0; --i) seq.push_back(i);
	seq.push_back(2 * n);

	ll sum = 1LL * n * (2 * n + 1);
	ll ans = 0;
	for (int i = 0; i < 2 * n; ++i) {
		sum -= seq[i];
		ans += (i + 1) * sum;
	}

	cout << ans << '\n';
	cout << 2 * n << ' ';
	for (int i = 1; i <= n - 2; i++) cout << i << ' ';
	cout << 2 * n - 1 << '\n';
	cout << 2 * n - 2 << ' ';
	for (int i = n - 1; i <= 2 * n - 3; ++i) cout << i << ' ';
}