// BOJ 11403 경로 찾기
// DFS

#include <iostream>
#include <cstring>
using namespace std;

bool vis[101];
int n;
int mat[101][101], res[101][101];

void dfs(int curr, int start) {
	for (int i = 0; i < n; ++i) {
		if (!mat[curr][i] || vis[i]) continue;
		vis[i] = true;
		dfs(i, start);
		res[start][i] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> mat[i][j];

	for (int i = 0; i < n; ++i) {
		memset(vis, false, sizeof(vis));
		dfs(i, i);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << res[i][j] << ' ';
		cout << '\n';
	}

}