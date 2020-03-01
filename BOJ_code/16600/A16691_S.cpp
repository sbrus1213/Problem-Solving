// BOJ 16691 House Numbers
// Two Pointer

#include <iostream>
using namespace std;
#define ll long long

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll m, x, n, m_sum, n_sum;

	cin >> m;
	x = m + 1, n = m + 2;
	m_sum = m, n_sum = n;

	while (m_sum != n_sum) {
		if (m_sum > n_sum) {
			n_sum += (++n);
		}
		else {
			m_sum += x;
			n_sum -= (++x);
		}
	}

	cout << m << ' ' << x << ' ' << n;
}