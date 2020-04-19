// BOJ 17550 Inquiry I
// ±¸Çö

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	ll sum = 0;
	vector<ll> seq(n);
	for (int i = 0; i < n; ++i) {
		cin >> seq[i];
		sum += seq[i];
	}

	ll l = seq[0] * seq[0], ans = 0;
	sum -= seq[0];
	ans = l * sum;
	for (int i = 1; i < n - 1; ++i) {
		l += seq[i] * seq[i];
		sum -= seq[i];
		ans = max(ans, l * sum);
	}
	cout << ans;
}