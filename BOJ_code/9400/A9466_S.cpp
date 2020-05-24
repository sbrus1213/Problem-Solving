// BOJ 9466 텀 프로젝트
// DFS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nxt, vis, fin, res;

int dfs(int cur) {
	int ret = -1;
	if (!vis[nxt[cur]]) {
		vis[nxt[cur]] = vis[cur] + 1;
		ret = dfs(nxt[cur]);
		if (ret != -1 && ret <= vis[cur]) res[cur] = 1;
		if (ret == vis[cur]) ret = -1;
	}
	else if (!fin[nxt[cur]]) {
		res[cur] = 1;
		ret = (vis[nxt[cur]] == vis[cur] ? -1 : vis[nxt[cur]]);
	}
	fin[cur] = 1;
	return ret;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;

		nxt = vector<int>(n + 1);
		for (int i = 1; i <= n; ++i) cin >> nxt[i];

		vis = vector<int>(n + 1);
		fin = vector<int>(n + 1);
		res = vector<int>(n + 1);
		for (int i = 1; i <= n; ++i)
			if (!vis[i])
				vis[i] = 1, dfs(i);

		int ans = 0;
		for (int i = 1; i <= n; ++i)
			if (!res[i])
				ans++;

		cout << ans << '\n';
	}
}