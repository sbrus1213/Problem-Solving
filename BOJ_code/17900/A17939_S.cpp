// BOJ 17939 Gazzzua
// Greedy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> coin(n + 1);
	for (int i = 1; i <= n; ++i) cin >> coin[i];

	vector<int> mx(n + 1);
	for (int i = 1; i <= n; ++i) mx[i] = coin[i];

	int m = coin[n];
	for (int i = n - 1; i > 0; --i) {
		m = max(coin[i], m);
		mx[i] = m;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans += mx[i] - coin[i];
	cout << ans;
}