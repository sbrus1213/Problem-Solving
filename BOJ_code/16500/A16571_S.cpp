// BOJ 16571 알파 틱택토
// Dynamic Programming

#include <iostream>
#include <algorithm>
using namespace std;

int board[3][3], player, c;

bool isend(int who) {
	int i;
	for (i = 0; i < 3; ++i) if (board[i][0] != who) break; if (i == 3) return true;
	for (i = 0; i < 3; ++i) if (board[i][1] != who) break; if (i == 3) return true;
	for (i = 0; i < 3; ++i) if (board[i][2] != who) break; if (i == 3) return true;
	for (i = 0; i < 3; ++i) if (board[0][i] != who) break; if (i == 3) return true;
	for (i = 0; i < 3; ++i) if (board[1][i] != who) break; if (i == 3) return true;
	for (i = 0; i < 3; ++i) if (board[2][i] != who) break; if (i == 3) return true;
	for (i = 0; i < 3; ++i) if (board[i][i] != who) break; if (i == 3) return true;
	for (i = 0; i < 3; ++i) if (board[i][2 - i] != who) break; if (i == 3) return true;
	return false;
}

int game(int cur, int cnt) {
	int op = 3 - cur, res = (cur == player ? -1 : 1);

	if (isend(op)) {
		if (op == player) return 1;
		else return -1;
	}
	if (cnt == 9) return 0;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (!board[i][j]) {
				board[i][j] = cur;
				if (cur == player) res = max(res, game(op, cnt + 1));
				else res = min(res, game(op, cnt + 1));
				board[i][j] = 0;
			}
		}
	}
	return res;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 1) player++;
			else if (board[i][j] == 2) player--;
			if (board[i][j]) c++;
		}
	}
	if (player) player = 2;
	else player = 1;

	int res = game(player, c);
	if (res > 0) cout << 'W';
	else if (res < 0) cout << 'L';
	else cout << 'D';
}