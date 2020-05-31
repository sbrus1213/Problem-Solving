// BOJ 1717 집합의 표현
// union find DSU

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

	int n, q; cin >> n >> q;

	par = vector<int>(n + 1, -1);
	while (q--) {
		int c, x, y; cin >> c >> x >> y;
		if (c) {
			if (find(x) == find(y)) cout << "YES\n";
			else cout << "NO\n";
		}
		else merge(x, y);
	}
}