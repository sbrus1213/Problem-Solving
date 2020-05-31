// BOJ 11085 군사 이동
// heap & union find DSU

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int u, v, w;
};
bool operator< (node a, node b) {
	return a.w < b.w;
}

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
	int s, e; cin >> s >> e;

	priority_queue<node> road;
	while (m--) {
		int s, e, w; cin >> s >> e >> w;
		road.push({ s, e, w });
	}

	int ans = 100000;
	par = vector<int>(n, -1);
	while (find(s) != find(e) && !road.empty()) {
		auto x = road.top(); road.pop();
		merge(x.u, x.v);
		ans = x.w;
	}
	cout << ans;
}