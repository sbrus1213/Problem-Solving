// BOJ 1089 ø§∏Æ∫£¿Ã≈Õ
// «ÿΩÃ

#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	string s[5];
	for (int i = 0; i < 5; ++i) cin >> s[i];

	int num[10] = { 0X7B6F, 0X1249, 0X73E7, 0X73CF, 0X5BC9, 0X79CF, 0X79EF, 0X7249, 0X7BEF, 0X7BCF };

	vector<vector<int> > prob(n);
	for (int i = 0; i < n; ++i) {
		int j = i * 4, x = 0;
		for (int l = 0; l < 5; ++l) {
			for (int k = j; k < j + 3; ++k) {
				x <<= 1;
				if (s[l][k] == '#') x++;
			}
		}
		for (int k = 0; k < 10; ++k)
			if ((x & num[k]) == x) prob[i].push_back(k);
	}

	ll cnt = 1;
	for (int i = 0; i < n; ++i) cnt *= prob[i].size();

	if (!cnt) cout << -1;
	else {
		ll t = 1;
		double ans = 0;
		for (int i = n - 1; i >= 0; --i) {
			for (int j : prob[i])
				ans += (double)j * t / prob[i].size();
			t *= 10;
		}
		cout << fixed;
		cout.precision(6);
		cout << ans;
	}
}