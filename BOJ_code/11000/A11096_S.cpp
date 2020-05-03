// BOJ 11096 UnDetected
// Union find

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct circle {
	int x, y, r;
};

vector<int> par, l, r;

int find(int i) {
	if (par[i] < 0) return i;
	else return par[i] = find(par[i]);
}
bool merge(int x, int y) {
	x = find(x), y = find(y);

	if (x == y) return false;

	l[y] = min(l[y], l[x]);
	r[y] = max(r[y], r[x]);
	par[x] = y;
	if (l[y] == 0 && r[y] == 200) return true;
	else return false;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<circle> C(n);
	for (int i = 0; i < n; ++i)
		cin >> C[i].x >> C[i].y >> C[i].r;

	vector<vector<int>> con(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (pow(C[i].x - C[j].x, 2) + pow(C[i].y - C[j].y, 2) < pow(C[i].r + C[j].r, 2))
				con[i][j] = con[j][i] = 1;

	l = vector<int>(n);
	r = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		l[i] = max(0, C[i].x - C[i].r);
		r[i] = min(200, C[i].x + C[i].r);
	}

	par = vector<int>(n, -1);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		bool fl = true;
		if (l[find(i)] == 0 && r[find(i)] == 200) fl = false;
		for (int j = i - 1; j >= 0; --j) {
			if (!con[i][j]) continue;
			if (merge(i, j)) fl = false;
		}
		if (!fl) break;
		ans++;
	}

	cout << ans;
}