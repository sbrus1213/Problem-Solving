// BOJ 11091 Quick Brown Fox
// string

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	cin.ignore(1);
	while (tc--) {
		string str; getline(cin, str);

		bool alp[26] = {};
		for (char c : str) {
			if (c >= 'a' && c <= 'z') alp[c - 'a'] = 1;
			else if (c >= 'A' && c <= 'Z') alp[c - 'A'] = 1;
		}

		bool fl = true;
		for (int i = 0; i < 26; ++i) if (!alp[i]) fl = false;

		if (fl) cout << "pangram\n";
		else {
			cout << "missing ";
			for (int i = 0; i < 26; ++i) if (!alp[i]) cout << (char)(i + 'a');
			cout << '\n';
		}
	}
}