// BOJ 13418 학교 탐방하기
// MST

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int u, v, w;
};

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

	vector<Edge> edge(m + 1);
	for (auto& e : edge) cin >> e.u >> e.v >> e.w;

	int mc = 0;
	par = vector<int>(n + 1, -1);
	sort(edge.begin(), edge.end(), [&](Edge a, Edge b) {
		return a.w > b.w;
		});
	for (auto& e : edge)
		if (merge(e.u, e.v))
			mc += e.w == 0;

	int Mc = 0;
	par = vector<int>(n + 1, -1);
	sort(edge.begin(), edge.end(), [&](Edge a, Edge b) {
		return a.w < b.w;
		});
	for (auto& e : edge)
		if (merge(e.u, e.v))
			Mc += e.w == 0;

	cout << Mc * Mc - mc * mc;
}