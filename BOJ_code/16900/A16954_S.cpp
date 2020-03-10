// BOj 16954 움직이는 미로 탈출
// BFS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	char bo[8][8];
	bool wall[8][8] = {};
	for (int i = 7; i >= 0; --i)
		for (int j = 0; j < 8; ++j) {
			cin >> bo[i][j];
			if (bo[i][j] == '#') wall[i][j] = 1;
		}

	vector<pii > candi = { { 0, 0 } }, next;
	int di[] = { -1,-1,-1,0,0,0,1,1,1 }, dj[] = { -1,0,1,-1,0,1,-1,0,1 };
	for (int cnt = 0; cnt < 8; ++cnt) {
		bool check[8][8] = {};
		for (auto& can : candi) {
			int cx = can.first, cy = can.second;
			for (int k = 0; k < 9; ++k) {
				int nx = cx + di[k], ny = cy + dj[k];
				if (nx < 0 || nx > 8) continue;
				if (ny < 0 || ny > 8) continue;
				if (wall[nx][ny]) continue;
				if (check[nx][ny]) continue;
				check[nx][ny] = 1;
				next.push_back({ nx, ny });
			}
		}
		for (int i = 0; i < 8; ++i) 
			for (int j = 0; j < 8; ++j) 
				if (!i) wall[i][j] = 0;
				else if (wall[i][j]) wall[i][j] = 0, wall[i - 1][j] = 1;

		candi.clear();
		for (auto& nxt : next)
			if (!wall[nxt.first][nxt.second])
				candi.push_back(nxt);
		next.clear();
	}
	if (candi.size() > 0) cout << 1;
	else cout << 0;
}