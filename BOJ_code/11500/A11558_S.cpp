// BOJ 11558 The Game of Death
// DFS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mxn = 10001;

int nxt[mxn], vis[mxn];

void dfs(int cur) {
	if (vis[nxt[cur]]) return;
	vis[nxt[cur]] = vis[cur] + 1;
	dfs(nxt[cur]);
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		fill(nxt, nxt + mxn, 0);
		fill(vis, vis + mxn, 0);
		for (int i = 1; i <= n; ++i)
			cin >> nxt[i];
		vis[1] = 0;
		dfs(1);
		cout << vis[n] << '\n';
	}
}