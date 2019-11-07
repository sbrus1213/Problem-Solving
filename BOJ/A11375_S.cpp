// BOJ 11375 ¿­Ç÷°­È£
// Bipartite Matching

#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int matched[1001];
bool vis[1001];
bool can[1001][1001];

bool matching(int curr, int prev) {
	vis[curr] = true;

	for (int i = 1; i <= m; ++i) {
		if (i == prev) continue;

		if (can[curr][i] && matched[i] == -1) {
			matched[i] = curr;
			return true;
		}
	}

	for (int i = 1; i <= m; ++i) {
		if (i == prev) continue;

		if (can[curr][i] && !vis[matched[i]] && matching(matched[i], i)) {
			matched[i] = curr;
			return true;
		}
		else continue;
	}

	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		int c;
		cin >> c;

		for (int j = 0; j < c; ++j) {
			int x;
			cin >> x;
			can[i][x] = true;
		}
	}

	int res = 0;
	memset(matched, -1, sizeof(matched));
	for (int i = 1; i <= n; ++i) {
		memset(vis, false, sizeof(vis));

		if (matching(i, 0)) res++;
	}

	cout << res;
}