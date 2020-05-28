// BOJ 16634 Run-Length Encoding, Run!
// string

#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	string e, s; cin >> e >> s;
	int len = s.size();
	if (e == "E") {
		for (int i = 0; i < len; ) {
			int c = 0;
			char ch = s[i];
			while (i < len && s[i] == ch) {
				c++;
				i++;
			}
			cout << ch << c;
		}
	}
	else {
		for (int i = 0; i < len; i += 2) {
			int c = s[i + 1] - '0';
			for (int j = 0; j < c; ++j)
				cout << s[i];
		}
	}

	return 0;
}
