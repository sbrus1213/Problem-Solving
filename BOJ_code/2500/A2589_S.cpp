// BOJ 2589 º¸¹°¼¶
// BFS

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
#define x first
#define y second

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	char jew[51][51];
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> jew[i][j];

	int di[4] = { 0, -1, 0, 1 }, dj[4] = { -1, 0, 1, 0 }, mx = 0;
	bool chk[51][51];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (jew[i][j] == 'W') continue;
			memset(chk, false, sizeof chk);
			pii s = pii(i, j);
			chk[s.x][s.y] = true;

			int tmp = 0;
			queue<pii> Q;
			Q.push(s);
			while (!Q.empty()) {
				int sz = Q.size();
				tmp++;
				for (int c = 0; c < sz; ++c) {
					pii cur = Q.front(); Q.pop();
					for (int k = 0; k < 4; ++k) {
						pii nxt = pii(cur.x + di[k], cur.y + dj[k]);
						if (nxt.x < 0 || nxt.x >= n) continue;
						if (nxt.y < 0 || nxt.y >= m) continue;
						if (jew[nxt.x][nxt.y] == 'W') continue;
						if (chk[nxt.x][nxt.y]) continue;
						chk[nxt.x][nxt.y] = true;
						Q.push(nxt);
					}
				}
			}
			mx = max(mx, tmp - 1);
		}
	}
	cout << mx;
}