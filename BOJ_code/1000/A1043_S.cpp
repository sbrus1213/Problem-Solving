// BOJ 1043 거짓말
// Disjoint set

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> par;
int find(int i) {
	if (par[i] < 0) return i;
	return par[i] = find(par[i]);
}
bool merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return false;
	par[y] = x;
	return true;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	par = vector<int>(n + 1, -1);

	int k; cin >> k;
	vector<int> know(n + 1);
	know[0] = 1;
	for (int i = 0; i < k; ++i) {
		int x; cin >> x;
		merge(0, x);
	}

	vector<vector<int>> party(m);
	for (int i = 0; i < m; ++i) {
		int c; cin >> c;
		party[i] = vector<int>(c);
		for (int& x : party[i])
			cin >> x;
		for (int j = 1; j < c; ++j)
			merge(party[i][j - 1], party[i][j]);
	}

	for (int i = 1; i <= n; ++i)
		if (find(0) == find(i))
			know[i] = 1;

	int ans = 0;
	for (int i = 0; i < m; ++i)
		if (know[find(party[i][0])] == 0)
			ans++;
	cout << ans;
}