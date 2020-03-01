// BOJ 3606 Celluar Automaton
// Exponentiation by Squaring

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, d, k;
	ll mod;
	cin >> n >> mod >> d >> k;

	vector<ll> cell(n), env(n);

	for (int i = 0; i < n; ++i) cin >> cell[i];

	env[0] = 1;
	for (int i = 1; i <= d; ++i) env[i] = env[n - i] = 1;

	while (k) {
		if (k % 2) {
			vector<ll> tmp(n);
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					tmp[i] = (tmp[i] + cell[(i + j) % n] * env[j]) % mod;

			for (int i = 0; i < n; ++i) cell[i] = tmp[i];
		}
		k >>= 1;

		vector<ll> tmp(n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				tmp[i] = (tmp[i] + env[j] * env[(i + j) % n]) % mod;

		for (int i = 0; i < n; ++i) env[i] = tmp[i];
	}

	for (int i = 0; i < n; ++i) cout << cell[i] << ' ';
}