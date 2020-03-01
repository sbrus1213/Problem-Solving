// BOJ 2842 집배원 한상덕
// DFS

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
#define BtoE(vec) vec.begin(), vec.end()

bool vis[51][51];
int n, res = 1000001, sx, sy, Ks, hmap[51][51], low, high, uhs, sh,
dx[8] = { -1,-1,-1,0,1,1,1,0 }, dy[8] = { -1,0,1,-1,-1,0,1,1 };
char cmap[51][51];
set<int> hs;
vector<int> hv;

bool isin(int i, int j) {
	return (i >= 0 && j >= 0 && i < n && j < n);
}
int dfs(int cx, int cy, int _min, int _max) {
	int res = 0;

	vis[cx][cy] = true;
	if (cmap[cx][cy] == 'K') res++;

	for (int k = 0; k < 8; k++) {
		int nx = cx + dx[k], ny = cy + dy[k];
		if (isin(nx, ny) && !vis[nx][ny] && hmap[nx][ny] >= _min && hmap[nx][ny] <= _max)
			res += dfs(nx, ny, _min, _max);
	}

	return res;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> cmap[i][j];
			if (cmap[i][j] == 'P') sx = i, sy = j;
			if (cmap[i][j] == 'K') Ks++;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> hmap[i][j];
			hs.insert(hmap[i][j]);
		}

	hv.assign(BtoE(hs));
	uhs = hv.size();
	low = high = 0;
	sh = hmap[sx][sy];
	while (high < uhs) {
		memset(vis, false, sizeof vis);
		if (dfs(sx, sy, hv[low], hv[high]) == Ks && sh >= hv[low] && sh <= hv[high]) {
			res = min(res, hv[high] - hv[low]);
			if (low != high)low++;
			else high++;
		}
		else high++;
	}

	cout << res;
}