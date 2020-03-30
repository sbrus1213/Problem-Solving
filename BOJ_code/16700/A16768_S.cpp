// BOJ 16768 Mooyo Mooyo
// DFS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k, di[4] = { -1,0,1,0 }, dj[4] = { 0,-1,0,1 };
bool chk[1001][11];
char mymy[1001][11];

int dfs(int cx, int cy, bool flag) {
	int ret = 1;
	chk[cx][cy] = 1;
	for (int k = 0; k < 4; ++k) {
		int nx = cx + di[k], ny = cy + dj[k];
		if (nx < 0 || nx >= n) continue;
		if (ny < 0 || ny >= 10) continue;
		if (chk[nx][ny] == 1) continue;
		if (mymy[cx][cy] != mymy[nx][ny]) continue;
		ret += dfs(nx, ny, flag);
	}
	if (flag) mymy[cx][cy] = '0';
	return ret;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 10; ++j)
			cin >> mymy[i][j];

	while (1) {
		bool flag = false;
		memset(chk, false, sizeof(chk));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < 10; ++j)
				if (!chk[i][j] && mymy[i][j] > '0') {
					int res = dfs(i, j, false);
					if (res >= k) {
						memset(chk, false, sizeof(chk));
						flag = true;
						dfs(i, j, true);
					}
				}

		if (!flag) break;

		for (int j = 0; j < 10; ++j) {
			vector<char> v;
			for (int i = n - 1; i >= 0; --i)
				if (mymy[i][j] != '0') v.push_back(mymy[i][j]);
			if (v.size() == n) continue;
			for (int i = 0, k = n - 1; i < v.size(); ++i, --k)
				mymy[k][j] = v[i];
			for (int i = n - 1 - v.size(); i >= 0; --i) mymy[i][j] = '0';
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 10; ++j)
			cout << mymy[i][j];
		cout << '\n';
	}
}