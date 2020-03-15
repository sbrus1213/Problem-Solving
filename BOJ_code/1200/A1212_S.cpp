// BOJ 1212 8진수 2진수
// 수학

#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	string b[8] = { "000","001","010","011","100","101","110","111" };

	if (s[0] > '3') cout << b[s[0] - '0'];
	else if (s[0] > '1') cout << b[s[0] - '0'][1] << b[s[0] - '0'][2];
	else cout << b[s[0] - '0'][2];
	for (int i = 1; i < s.size(); ++i) cout << b[s[i] - '0'];
}