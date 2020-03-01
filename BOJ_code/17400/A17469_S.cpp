// BOJ 17469 Æ®¸®ÀÇ »ö±ò°ú Äõ¸®
// offline query

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int mxn = 100001;

struct query {
	int q, x;
};

vector<int> par;
vector<set<int> > color;
vector<query> Q;

int find(int i) {
	if (par[i] < 0) return i;
	return par[i] = find(par[i]);
}
void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (color[x].size() > color[y].size()) {
		par[y] = x;
		color[x].insert(color[y].begin(), color[y].end());
		color[y].clear();
	}
	else {
		par[x] = y;
		color[y].insert(color[x].begin(), color[x].end());
		color[x].clear();
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;

	vector<int> adj(n + 1);
	for (int i = 2; i <= n; ++i) cin >> adj[i];

	color = vector<set<int> >(n + 1);
	for (int i = 1; i <= n; ++i) {
		int c; cin >> c;
		color[i].insert(c);
	}
	for (int i = 0; i < n - 1 + q; ++i) {
		int c, a; cin >> c >> a;
		Q.push_back({ c, a });
	}

	par = vector<int>(n + 1);
	fill(par.begin(), par.end(), -1);
	vector<int> ans;
	for (int i = n - 2 + q; i >= 0; --i) {
		query qq = Q[i];
		if (qq.q == 1) merge(qq.x, adj[qq.x]);
		else ans.push_back(color[find(qq.x)].size());
	}

	for (int i = q - 1; i >= 0; --i) cout << ans[i] << '\n';
}