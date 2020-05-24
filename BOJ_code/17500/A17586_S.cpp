// BOJ 17586 Diagonal Cut
// 수학 gcd

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (a > b) swap(a, b);
	while (a) {
		b %= a;
		swap(a, b);
	}
	return b;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	ll n, m; cin >> n >> m;
	ll g = gcd(n, m);
	n /= g, m /= g;

	if ((n % 2) ^ (m % 2)) cout << 0;
	else cout << g;
}