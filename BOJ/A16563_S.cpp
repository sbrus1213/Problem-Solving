// BOJ 16563 어려운 소인수분해
// Number theorem

#include <iostream>
using namespace std;
#define ll	long long

int minp[5000001];
void era() {
	for (ll i = 2; i <= 5000000; ++i) {
		if (minp[i]) continue;
		for (ll j = i; i * j <= 5000000; ++j) {
			if (minp[i * j]) continue;
			minp[i * j] = i;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	era();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x, pi = 0;
		cin >> x;
		while (minp[x]) {
			cout << minp[x] << ' ';
			x /= minp[x];
		}
		cout << x << '\n';
	}
}