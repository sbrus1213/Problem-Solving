// BOJ 8933 MCS
// string

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int k; cin >> k;
		string s; cin >> s;

		int mx = 0;
		ll d = 0, ten[] = { 1, 1000, 1000000, 1000000000 };
		char dna[] = { 'A','G','T','C' };
		map<ll, int> dic;
		for (int i = 0; i < s.size(); ++i) {
			for (int j = 0; j < 4; ++j)
				if (s[i] == dna[j]) d += ten[j];
			if (i >= k - 1) {
				dic[d]++;
				mx = max(mx, dic[d]);
				for (int j = 0; j < 4; ++j)
					if (s[i - k + 1] == dna[j]) d -= ten[j];
			}
		}
		cout << mx << '\n';
	}
}