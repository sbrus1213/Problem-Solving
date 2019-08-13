// BOJ 16427 Time Limits

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, s, m = 0;

	cin >> n >> s;

	for (int i = 0; i < n; ++i) {
		int x;

		cin >> x;

		m = max(m, x);
	}

	m *= s;
	cout << (m % 1000 ? (m / 1000) + 1 : (m / 1000));
}