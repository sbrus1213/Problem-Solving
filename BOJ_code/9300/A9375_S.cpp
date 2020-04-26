// BOJ 9375 ÆÐ¼Ç¿Õ ½ÅÇØºó
// ÁýÇÕ

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;

		map<string, int> dic;
		for (int i = 0; i < n; ++i) {
			string a, b; cin >> a >> b;
			dic[b]++;
		}

		int ans = 1;
		for (auto it = dic.begin(); it != dic.end(); it++) {
			ans *= (it->second + 1);
		}
		cout << ans - 1 << '\n';
	}
}