// BOJ 11088 Cantina of Babel
// SCC

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> vis, mxs;

struct scc {
	vector<vector<int> > adj, SCC;
	vector<int> dfsn, fin, ST;
	int v, sz, cnt;
	scc(vector<vector<int>>& adj_) :adj(move(adj_)) {
		v = adj.size();
		dfsn = vector<int>(v);
		fin = vector<int>(v);
		sz = cnt = 0;

		for (int i = 0; i < v; ++i)
			if (!dfsn[i])
				dfs(i);
	}
	int dfs(int cur) {
		dfsn[cur] = ++cnt;
		ST.push_back(cur);

		int low = dfsn[cur];
		for (int next : adj[cur]) {
			if (!dfsn[next]) low = min(low, dfs(next));
			else if (!fin[next]) low = min(low, dfsn[next]);
		}
		if (low == dfsn[cur]) {
			SCC.push_back({});
			while (!ST.empty()) {
				int elem = ST.back(); ST.pop_back();
				SCC[sz].push_back(elem);
				fin[elem] = 1;
				if (elem == cur) break;
			}
			sz++;
		}
		return low;
	}
	int solve() {
		int ret = 0;
		for (int i = 0; i < sz; ++i) ret = max(ret, (int)SCC[i].size());
		return ret;
	}
};

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;
	cin.ignore(1);

	map<string, int> idx;
	map<int, vector<int>> speak, under;
	int cnt = 0;

	for (int i = 1; i <= n; ++i) {
		string s; getline(cin, s);
		int sz = s.size(), c = 0;
		string tmp = "";
		for (int j = 0; j <= sz; ++j) {
			if (j == sz || s[j] == ' ') {
				if (!c);
				else if (c == 1) {
					if (!idx[tmp]) idx[tmp] = ++cnt;
					speak[idx[tmp]].push_back(i);
				}
				else {
					if (!idx[tmp]) idx[tmp] = ++cnt;
					under[idx[tmp]].push_back(i);
				}
				++c;
				tmp = "";
			}
			else tmp += s[j];
		}
	}

	adj = vector<vector<int>>(n + 1);
	for (int i = 1; i <= cnt; ++i) {
		auto& vec = speak[i];
		int sz = vec.size();
		for (int j = 0; j < sz; ++j) {
			for (int k = j + 1; k < sz; ++k) {
				adj[vec[j]].push_back(vec[k]);
				adj[vec[k]].push_back(vec[j]);
			}
		}
	}
	for (int i = 1; i <= cnt; ++i) {
		auto& vec1 = speak[i], vec2 = under[i];
		int sz1 = vec1.size(), sz2 = vec2.size();
		for (int j = 0; j < sz1; ++j)
			for (int k = 0; k < sz2; ++k)
				adj[vec1[j]].push_back(vec2[k]);
	}

	scc S(adj);
	int ans = S.solve();
	cout << n - ans;
}

//// BOJ 11088 Cantina of Babel
//// floyd warshall & DFS
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//vector<vector<int>>adj;
//vector<int> vis;
//int dfs(int n, int cur) {
//	vis[cur] = 1;
//	int res = 1;
//	for (int i = 1; i <= n; ++i) {
//		if (vis[i]) continue;
//		if (adj[cur][i] && adj[i][cur]) res += dfs(n, i);
//	}
//	return res;
//}
//
//int main() {
//	cin.tie(NULL); ios_base::sync_with_stdio(false);
//
//	int n; cin >> n;
//	cin.ignore(1);
//
//	map<string, int> idx;
//	map<int, vector<int>> speak, under;
//	int cnt = 0;
//
//	for (int i = 1; i <= n; ++i) {
//		string s; getline(cin, s);
//		int sz = s.size(), c = 0;
//		string tmp = "";
//		for (int j = 0; j <= sz; ++j) {
//			if (j == sz || s[j] == ' ') {
//				if (!c);
//				else if (c == 1) {
//					if (!idx[tmp]) idx[tmp] = ++cnt;
//					speak[idx[tmp]].push_back(i);
//				}
//				else {
//					if (!idx[tmp]) idx[tmp] = ++cnt;
//					under[idx[tmp]].push_back(i);
//				}
//				++c;
//				tmp = "";
//			}
//			else tmp += s[j];
//		}
//	}
//
//	adj = vector<vector<int>>(n + 1, vector<int>(n + 1));
//	for (int i = 1; i <= cnt; ++i) {
//		auto& vec = speak[i];
//		int sz = vec.size();
//		for (int j = 0; j < sz; ++j) {
//			for (int k = j + 1; k < sz; ++k) {
//				adj[vec[j]][vec[k]] = 1;
//				adj[vec[k]][vec[j]] = 1;
//			}
//		}
//	}
//	for (int i = 1; i <= cnt; ++i) {
//		auto& vec1 = speak[i], vec2 = under[i];
//		int sz1 = vec1.size(), sz2 = vec2.size();
//		for (int j = 0; j < sz1; ++j)
//			for (int k = 0; k < sz2; ++k)
//				adj[vec1[j]][vec2[k]] = 1;
//	}
//
//	for (int k = 1; k <= n; ++k)
//		for (int i = 1; i <= n; ++i)
//			for (int j = 1; j <= n; ++j)
//				adj[i][j] |= adj[i][k] & adj[k][j];
//
//	vis = vector<int>(n + 1);
//	int ans = 0;
//	for (int i = 1; i <= n; ++i)
//		if (!vis[i])
//			ans = max(ans, dfs(n, i));
//	cout << n - ans;
//}