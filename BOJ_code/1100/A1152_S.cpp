// BOJ 1152 단어의 개수
// string

#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s; getline(cin, s);

	int ans = 0;
	char prv = ' ';
	for (char c : s) {
		if (c != ' ') {
			if (prv == ' ') ans++;
			prv = c;
		}
		else prv = ' ';
	}
	cout << ans;
}