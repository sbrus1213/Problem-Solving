// BOJ 17352 여러분의 다리가 되어 드리겠습니다.
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
	par[x] = y;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	par = vector<int>(n + 1, -1);
	for (int i = 2; i < n; ++i) {
		int x, y; cin >> x >> y;
		merge(x, y);
	}

	vector<int> ans;
	for (int i = 1; i <= n; ++i)
		if (par[i] == -1) ans.push_back(i);

	for (int x : ans) cout << x << ' ';
}