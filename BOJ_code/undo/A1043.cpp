// BOJ 1043 °ÅÁþ¸»
// union find

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int par[51];
int find(int x) {
	if (par[x] < 0) return x;
	return par[x] = find(par[x]);
}
void merge(int x, int y) {
	x = find(x), y = find(y);
	par[y] = x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> crane(n);
	for (int i = 0; i < n; ++i) cin >> crane[i];
	sort(crane.begin(), crane.end());

	int n, m; cin >> n >> m;

	fill(par, par + 51, -1);

	int x; cin >> x;
	vector<int> tr(x);
	for (int i = 0; i < x; ++i) cin >> tr[i];

	for (int i = 0; i < m; ++i) {

	}
}