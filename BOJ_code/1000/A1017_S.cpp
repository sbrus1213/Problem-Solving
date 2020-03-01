// BOJ 1017 ¼Ò¼ö ½Ö
// eratosthenes sieve & bipartite matching

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool prime[50001];
int n, f, a, b;
vector<vector<int> > adj(100);
vector<int> vis(100), from(100), A, B;

void init() {
	fill(prime, prime + 50001, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= 50000; ++i) {
		if (!prime[i]) continue;
		for (int j = 2; i * j <= 50000; ++j)
			prime[i * j] = false;
	}
}

bool dfs(int cur) {
	if (vis[cur]) return false;
	vis[cur] = true;
	for (int& next : adj[cur]) {
		if (from[next - 50] == -1 || dfs(from[next - 50])) {
			from[next - 50] = cur;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	init();
	cin >> n >> f;

	for (int i = 1; i < n; ++i) {
		int x; cin >> x;
		if ((f + x) % 2 == 1) A.push_back(x);
		else B.push_back(x);
	}

	a = A.size(), b = B.size();
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			int tmp = A[i] + B[j];
			if (prime[tmp]) adj[i].push_back(j + 50);
		}
	}

	vector<int> ans;
	for (int i = 0; i < a; ++i) {
		if (!prime[f + A[i]]) continue;
		int res = 1;
		fill(from.begin(), from.end(), -1);
		for (int j = 0; j < a; ++j) {
			if (i == j) continue;
			fill(vis.begin(), vis.end(), false);
			if (dfs(j)) res++;
		}
		if (res * 2 == n) ans.push_back(A[i]);
	}
	if (!ans.size()) cout << -1;
	else {
		sort(ans.begin(), ans.end());
		for (int& elem : ans) cout << elem << ' ';
	}
}