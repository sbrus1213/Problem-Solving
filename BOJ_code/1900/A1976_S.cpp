// BOJ 1976 여행 가자
// Union find DSU

#include <iostream>
#include <vector>
using namespace std;

vector<int> par;
int find(int i) {
	if (par[i] < 0) return i;
	return par[i] = find(par[i]);
}
void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	par[y] = x;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	par = vector<int>(n + 1, -1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int x; cin >> x;
			if (x) merge(i, j);
		}
	}

	int prv; cin >> prv;
	while (--m) {
		int cur; cin >> cur;
		if (find(prv) != find(cur)) {
			cout << "NO";
			return 0;
		}
		prv = cur;
	}
	cout << "YES";
}