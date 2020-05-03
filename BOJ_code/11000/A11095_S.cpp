// BOJ 11095 Torn to Pieces
// DFS

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> adj(1);
vector<int> vis, path;

bool dfs(int cur, int dest) {
	vis[cur] = 1;
	if (cur == dest) {
		path.push_back(cur);
		return true;
	}
	for (int nxt : adj[cur]) {
		if (vis[nxt]) continue;
		bool res = dfs(nxt, dest);
		if (res) {
			path.push_back(cur);
			return res;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;
	cin.ignore(1);

	int cnt = 0;
	map<string, int> idx;
	map<int, string> str;
	for (int i = 0; i < n; ++i) {
		string s; getline(cin, s);

		string tmp = "", u;
		int len = s.size(), c = 0;
		for (int j = 0; j <= len; ++j) {
			if (j == len || s[j] == ' ') {
				if (!idx[tmp]) {
					idx[tmp] = ++cnt;
					str[cnt] = tmp;
					adj.push_back({});
				}
				if (!c) u = tmp;
				else {
					adj[idx[u]].push_back(idx[tmp]);
					adj[idx[tmp]].push_back(idx[u]);
				}

				c++;
				tmp = "";
			}
			else tmp += s[j];
		}
	}

	string s, e; cin >> s >> e;
	int si = idx[s], ei = idx[e];

	if (!si || !ei) cout << "no route found";
	else {
		vis = vector<int>(cnt + 1);
		dfs(si, ei);
		if (path.empty()) cout << "no route found";
		else {
			reverse(path.begin(), path.end());
			for (int x : path) cout << str[x] << ' ';
		}
	}
}