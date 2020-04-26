// BOJ 1182 부분수열의 합
// Brute force

#include <iostream>
#include <algorithm>
using namespace std;

int n, s, seq[20], cnt;

void fn(int i, int sum) {
	if (i == n) {
		if (s == sum) cnt++;
		return;
	}

	fn(i + 1, sum + seq[i]);
	fn(i + 1, sum);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> s;
	for (int i = 0; i < n; ++i) cin >> seq[i];

	fn(0, 0);
	if (s) cout << cnt;
	else cout << cnt - 1;
}