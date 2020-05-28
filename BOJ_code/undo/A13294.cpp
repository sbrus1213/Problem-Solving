// BOJ 13294 
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
const ll mod = 1e14;

vector<int> mul;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	string s; cin >> s;

	for (int i = 0; i < s.size(); i += 14) {

	}
	int cnt = 0;
	for (int i = s.size() - 1; i >= 0; --i) {
		if (s[i] != '0') break;
		else cnt++;
	}

	if (cnt <= 3) {
		ll sn = stoi(s), m = 1;
		for (int i = 1; i < 20; ++i) {
			m = m * i;
			if (m == sn) {
				cout << i;
				return 0;
			}
		}
	}

	int tmp = 0, x;
	for (int i = 5;; i += 5) {
		if (tmp + get(i) == cnt) {
			x = i; break;
		}
		tmp += get(i);
	}

	string t = s.substr(s.size() - cnt - 9, 9);
	ll mul = 1, mod = 1000000000, tn = stoi(t);
	for (int i = 1; i < x; ++i) {
		if (i % 5) mul = (mul * i) % mod;
		else {
			mul *= i;
			mul /= pow(10, get(i));
			mul %= mod;
		}
	}
	if (mul == tn) {
		cout << x;
		return 0;
	}
	mul *= x;
	mul /= pow(10, get(x));
	mul %= mod;
	for (int i = x + 1; i < x + 5; ++i) {
		mul = (mul * i) % mod;
		if (mul == tn) {
			cout << i;
			return 0;
		}
	}

}