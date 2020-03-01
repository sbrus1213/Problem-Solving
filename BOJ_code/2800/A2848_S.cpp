// BOJ 2848 ¾Ë°í½ºÆÌ ¾î
// Topological sort

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	 
	vector<string> word(n);
	for (int i = 0; i < n; ++i) cin >> word[i];

	vector<vector<int> > adj(26);
	vector<int> ind(26);
	for (int i = 1; i < n; ++i) {
		string s1 = word[i - 1], s2 = word[i];
		int sz = min(s1.size(), s2.size()), j;
		for (j = 0; j < sz; ++j) {
			if (s1[j] == s2[j]) continue;
			else {
				adj[s1[j] - 'a'].push_back(s2[j] - 'a');
				ind[s2[j] - 'a']++;
				break;
			}
		}
		if (j == sz && s1.size() > sz) {
			cout << '!';
			return 0;
		}
	}

	vector<bool> exist(26);
	for (int i = 0; i < n; ++i)
		for (char c : word[i])
			exist[c - 'a'] = 1;

	queue<int> Q;
	for (int i = 0; i < 26; ++i) if (!ind[i] && exist[i]) Q.push(i);

	bool unique = true;
	vector<bool> check(26);
	vector<int> ans;
	while (!Q.empty()) {
		if (Q.size() > 1) unique = false;
		int cur = Q.front(); Q.pop();
		check[cur] = true;
		ans.push_back(cur);
		for (int next : adj[cur]) {
			ind[next]--;
			if (!ind[next]) Q.push(next);
		}
	}

	bool can = true;
	for (int i = 0; i < 26; ++i) if (!check[i] && exist[i]) can = false;

	if (can) {
		if (unique) for (int c : ans) cout << (char)(c + 'a');
		else cout << '?';
	}
	else cout << '!';
}