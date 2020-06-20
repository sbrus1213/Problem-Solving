// BOJ 1786 찾기
// KMP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> get_fail(string& p) {
	int plen = p.size();
	vector<int> ret(plen);
	for (int i = 1, j = 0; i < plen; ++i) {
		while (j && p[i] != p[j])
			j = ret[j - 1];
		if (p[i] == p[j])
			ret[i] = ++j;
	}

	return ret;
}

vector<int> kmp(string& s, string& p) {
	int slen = s.length(), plen = p.length();
	vector<int> ret, fail = get_fail(p);
	for (int i = 0, j = 0; i < slen; ++i) {
		while (j && s[i] != p[j])
			j = fail[j - 1];
		if (s[i] == p[j]) {
			if (j == plen - 1) {
				ret.push_back(i - plen + 1);
				j = fail[j];
			}
			else j++;
		}
	}
	return ret;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	string tot, pat;
	getline(cin, tot);
	getline(cin, pat);

	auto ans = kmp(tot, pat);

	cout << ans.size() << '\n';
	for (int x : ans)
		cout << x + 1 << ' ';
}