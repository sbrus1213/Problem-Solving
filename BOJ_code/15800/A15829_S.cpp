// BOJ 15829 Hashing
// hashing

#include <iostream>
#include <string>
using namespace std;
using ll = long long;
const ll mod = 1234567891;
const ll r = 31;

int  main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int l; cin >> l;
	string s; cin >> s;
	ll res = 0, ri = 1;
	for (int i = 0; i < l; ++i) {
		res += (s[i] - 'a' + 1) * ri;
		res %= mod;
		ri = (ri * r) % mod;
	}
	cout << res;
}