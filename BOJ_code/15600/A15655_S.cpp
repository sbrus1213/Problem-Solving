// BOJ 15655 N°ú M (6)
// Backtracking

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool used[10];
int seq[10];
vector<int> ans;

void n_m(int n, int m, int k) {
	if (ans.size() == m) {
		for (int x : ans)
			cout << x << ' ';
		cout << '\n';
		return;
	}

	for (int i = k; i < n; ++i) {
		if (used[i]) continue;
		ans.push_back(seq[i]); used[i] = true;
		n_m(n, m, i + 1);
		ans.pop_back(); used[i] = false;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> seq[i];
	sort(seq, seq + n);

	n_m(n, m, 0);
}