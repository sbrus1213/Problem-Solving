// BOJ 2150 Strongly Connected Component
// SCC Tarjan

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mxv = 10001;

vector<vector<int> > adj(mxv), SCC;
vector<int> vis(mxv), fin(mxv), ST;
int sz, dfsn;

int dfs(int cur) {
	vis[cur] = ++dfsn;
	ST.push_back(cur);

	int low = vis[cur];
	for (int next : adj[cur]) {
		if (!vis[next]) low = min(low, dfs(next));
		else if (!fin[next]) low = min(low, vis[next]);
	}
	if (low == vis[cur]) {
		SCC.push_back({});
		while (!ST.empty()) {
			int elem = ST.back();
			ST.pop_back();
			SCC[sz].push_back(elem);
			fin[elem] = 1;
			if (elem == cur) break;
		}
		sz++;
	}
	return low;
}
bool comp(vector<int>& a, vector<int>& b) {
	return a[0] < b[0];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	fill(vis.begin(), vis.end(), 0);
	for (int i = 1; i <= v; ++i)
		if (!vis[i])
			dfs(i);

	for (auto& vec : SCC)
		sort(vec.begin(), vec.end());
	sort(SCC.begin(), SCC.end(), comp);

	cout << sz << '\n';
	for (int i = 0; i < sz; ++i) {
		for (int elem : SCC[i])
			cout << elem << ' ';
		cout << "-1\n";
	}
}

/*
// BOJ 2150 Strongly Connected Component
// SCC Kosaraju

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mxv = 10001;

vector<vector<int> > adj(mxv), rev_adj(mxv), SCC;
vector<int> vis(mxv), ST;
int sz;

void dfs(int cur) {
	vis[cur] = 1;
	for (int next : adj[cur]) {
		if (vis[next]) continue;
		dfs(next);
	}
	ST.push_back(cur);
}
void rev_dfs(int cur) {
	vis[cur] = true;
	for (int next : rev_adj[cur]) {
		if (vis[next]) continue;
		rev_dfs(next);
	}
	SCC[sz].push_back(cur);
}
bool comp(vector<int>& a, vector<int>& b) {
	return a[0] < b[0];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		rev_adj[v].push_back(u);
	}

	fill(vis.begin(), vis.end(), 0);
	for (int i = 1; i <= v; ++i)
		if (!vis[i])
			dfs(i);

	fill(vis.begin(), vis.end(), 0);
	while (!ST.empty()) {
		int cur = ST.back();
		ST.pop_back();
		if (vis[cur]) continue;

		SCC.push_back({});
		rev_dfs(cur);
		sz++;
	}

	for (auto& vec : SCC)
		sort(vec.begin(), vec.end());
	sort(SCC.begin(), SCC.end(), comp);

	cout << sz << '\n';
	for (int i = 0; i < sz; ++i) {
		for (int elem : SCC[i])
			cout << elem << ' ';
		cout << "-1\n";
	}
}
*/