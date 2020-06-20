// BOJ 13301 타일 장식물
// dynamic programming

#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	ll a = 1, b = 1;
	for (int i = 1; i < n; ++i) {
		ll t = a;
		a += b;
		b = t;
	}
	cout << (a + b) * 2;
}