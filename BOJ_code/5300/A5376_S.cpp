// BOJ 5376 소수를 분수로
// Number thoerem & GCD

#include <iostream>
#include <string>
using namespace std;
#define ll	long long

ll getgcd(ll a, ll b) {
	while (a) {
		if (a < b) swap(a, b);

		a %= b;
	}
	return b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;

	cin >> t;

	while (t--) {
		string str;

		cin >> str;

		ll l = str.size(), i, lu = 0, ld = 1, ru = 0, rd = 1;

		for (i = 2; i < l; ++i) {
			if (str[i] == '(') break;
			lu = (lu * 10) + str[i] - '0';
			ld *= 10;
		}
		if (i != l) {
			for (++i; i < l; ++i) {
				if (str[i] == ')') break;
				ru = (ru * 10) + str[i] - '0';
				rd *= 10;
			}
		}

		if (ru) rd = (rd - 1) * ld;
		else rd = 1;

		ll su, sd, gcd;

		gcd = getgcd(ld, rd);
		su = (ru * (ld / gcd)) + (lu * (rd / gcd));
		sd = (ld * (rd / gcd));

		gcd = getgcd(su, sd);
		cout << su / gcd << '/' << sd / gcd << '\n';
	}
}