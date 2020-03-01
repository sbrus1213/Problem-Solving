// BOJ 18116 ·Îº¿ Á¶¸³
// Disjoint set - Union Find

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int par[1000001];

int find(int i) {
	if (par[i] < 0) return i;
	return par[i] = find(par[i]);
}
int merge(int i, int j) {
	i = find(i), j = find(j);
	if (i == j) return par[i];

	par[i] += par[j];
	par[j] = i;
	return par[i];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;

	fill(par, par + 1000001, -1);
	for (int i = 0; i < n; ++i) {
		int x, y;
		char comm;
		cin >> comm;
		if (comm == 'I') {
			cin >> x >> y;
			merge(x, y);
		}
		else {
			cin >> x;
			cout << -par[find(x)] << '\n';
		}
	}
}