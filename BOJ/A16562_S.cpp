// BOJ 16562 Ä£±¸ºñ
// Disjoint set & Union find

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
#define BtoE(vec) vec.begin(), vec.end()
#define Pii pair<int, int>

int n, m, k, par[10001];
vector<Pii> cost;

int find(int i) {
	if (par[i] < 0) return i;
	return par[i] = find(par[i]);
}
bool merge(int i, int j) {
	i = find(i), j = find(j);
	if (i == j) return false;
	par[i] += par[j];
	par[j] = i;
	return true;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		cost.push_back(Pii(c, i + 1));
	}
	sort(BtoE(cost));

	memset(par, -1, sizeof(par));
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		merge(x, y);
	}

	int money = 0;
	for (int i = 0; i < n; ++i) {
		if (merge(0, cost[i].second)) {
			money += cost[i].first;
		}
	}

	if (money > k) cout << "Oh no";
	else cout << money;
}