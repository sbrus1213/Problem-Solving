// BOJ 10826 피보나치 수 4
// dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = (1e17);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	vector<ll> fibo[3] = { {0}, {1}, {1} };

	cin >> n;
	if (n < 3) {
		cout << fibo[n][0];
		return 0;
	}

	for (int i = 3; i <= n; i++) {
		fibo[i % 3] = fibo[(i + 2) % 3];
		for (int j = 0; j < fibo[(i + 1) % 3].size(); j++) {
			fibo[i % 3][j] += fibo[(i + 1) % 3][j];
		}
		for (int j = 0; j < fibo[i % 3].size(); j++) {
			if (fibo[i % 3][j] >= INF) {
				if (j == fibo[i % 3].size() - 1) {
					fibo[i % 3].push_back(fibo[i % 3][j] / INF);
					fibo[i % 3][j] = fibo[i % 3][j] % INF;
				}
				else {
					fibo[i % 3][j + 1] += fibo[i % 3][j] / INF;
					fibo[i % 3][j] = fibo[i % 3][j] % INF;
				}
			}
		}
	}
	reverse(fibo[n % 3].begin(), fibo[n % 3].end());
	cout << fibo[n % 3][0];
	for (int i = 1; i < fibo[n % 3].size(); i++) {
		int div = (INF / (fibo[n % 3][i] + 1)) / 10;
		while (div) {
			cout << '0';
			div /= 10;
		}
		cout << fibo[n % 3][i];
	}
}