// BOJ 13348 Memory Match
// string

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vector<string> card(n + 1);
	vector<int> chk(n + 1);
	for (int i = 0; i < m; ++i) {
		int c1, c2; string s1, s2; cin >> c1 >> c2 >> s1 >> s2;
		card[c1] = s1;
		card[c2] = s2;
		if (s1 == s2) chk[c1] = chk[c2] = -1;
	}

	int blk = 0, match = 0, know = 0;
	map<string, int> dic;
	for (int i = 1; i <= n; ++i) {
		if (chk[i] != -1) {
			if (card[i] == "") blk++;
			else {
				know++;
				if (!dic[card[i]])
					dic[card[i]] = 1;
				else {
					match++;
					know -= 2;
					dic[card[i]] = 0;
				}
			}
		}
	}

	if (!know && blk == 2) cout << match + 1;
	else if (know == blk) cout << match + know;
	else cout << match;
}