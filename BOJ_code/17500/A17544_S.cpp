// BOJ 17544 Canyon Crossing
// Binary search & bfs

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int dr[] = { 0, 1, 0, -1 }, dc[] = { 1, 0, -1, 0 };
int height[1010][1010];
bool chk[1010][1010];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r, c, k, mn = 1e9 + 3, mx = -1; cin >> r >> c >> k;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) {
			cin >> height[i][j];
			mn = min(mn, height[i][j]);
			mx = max(mx, height[i][j]);
		}

	int low = mn, high = mx + 1;
	while (low + 1 < high) {
		memset(chk, false, sizeof chk);

		int mid = (low + high) / 2, mm = -1;

		vector<queue<int>> q(k + 1);
		for (int j = 0; j < c; ++j) chk[0][j] = true;
		for (int j = 0; j < c; ++j) {
			if (height[0][j] >= mid) {
				q[0].push(j);
				mm = 0;
			}
			else if (k >= 1) q[1].push(j);
		}
		if (mm == -1) mm = 1;

		vector<int> res(c, -1);
		int cnt = 0;
		while (1) {
			if (mm > k) break;
			auto cur = q[mm].front(); q[mm].pop();
			int cr = cur / c, cc = cur % c;
			if (cr == r - 1) res[cc] = mm;
			cnt++;
			if (cnt == r * c) break;
			for (int l = 0; l < 4; ++l) {
				int nr = cr + dr[l], nc = cc + dc[l];
				if (nr < 0 || nr >= r)continue;
				if (nc < 0 || nc >= c) continue;
				if (chk[nr][nc]) continue;
				chk[nr][nc] = true;
				if (height[nr][nc] >= mid) q[mm].push(nr * c + nc);
				else if (mm < k) q[mm + 1].push(nr * c + nc);
			}
			for (; mm <= k && !q[mm].size(); ++mm);
		}

		bool fl = false;
		for (int j = 0; j < c; ++j) if (res[j] != -1) fl = true;

		if (fl) low = mid;
		else high = mid;
	}
	cout << low;
}