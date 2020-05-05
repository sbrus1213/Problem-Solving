// BOJ 1039 교환
// bfs

#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int si(string s) {
	int ret = 0;
	for (char c : s) ret = ret * 10 + c - '0';
	return ret;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	string n; int k; cin >> n >> k;
	k++;

	queue<string> q;
	q.push(n);
	map<int, int> dep;
	dep[si(n)] = 1;
	int ans = -1, l = n.size();
	for (int i = 2; i <= k; ++i) {
		int qsz = q.size();
		for (int j = 0; j < qsz; ++j) {
			auto cur = q.front(); q.pop();
			int ncur = si(cur);
			for (int a = 0; a < l; ++a) {
				for (int b = a + 1; b < l; ++b) {
					string nxt = cur;
					swap(nxt[a], nxt[b]);
					if (nxt[0] == '0') continue;
					int nnxt = si(nxt);
					if (dep[nnxt] == i) continue;
					dep[nnxt] = i;
					q.push(nxt);
					if (i == k) ans = max(ans, nnxt);
				}
			}
		}
	}

	cout << ans;
}