// BOJ 1730 판화
// 구현

#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	string s; cin >> s;
	char board[101][101] = {};
	int cx = 0, cy = 0, len = s.size();

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			board[i][j] = '.';

	if (s[0] == 'D') board[cx][cy] = '|';
	else board[cx][cy] = '-';

	for (int i = 0; i < len; ++i) {
		if (s[i] == 'D') cx++;
		else if (s[i] == 'U') cx--;
		else if (s[i] == 'R') cy++;
		else cy--;
		if (i == len - 1) break;

		if (s[i] == s[i + 1]) {
			if (s[i] == 'R' || s[i] == 'L') {
				if (board[cx][cy] == '|') board[cx][cy] = '+';
				else board[cx][cy] = '-';
			}
			else {
				if (board[cx][cy] == '-') board[cx][cy] = '+';
				else board[cx][cy] = '|';
			}
		}
		else board[cx][cy] = '+';
	}

	if (s[0] == 'D') {
		if (board[cx][cy] == '-') board[cx][cy] = '+';
		else board[cx][cy] = '|';
	}
	else {
		if (board[cx][cy] == '|') board[cx][cy] = '+';
		else board[cx][cy] = '-';
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << board[i][j];
		cout << '\n';
	}
}