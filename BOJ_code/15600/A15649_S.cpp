// BOJ 15649 N°ú M (1)
// Backtracking

#include <iostream>
#include <vector>
using namespace std;

bool used[10];
vector<int> ans;

void n_m(int n, int m) {
	if (ans.size() == m) {
		for (int x : ans)
			cout << x << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (used[i]) continue;
		ans.push_back(i); used[i] = true;
		n_m(n, m);
		ans.pop_back(); used[i] = false;
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	n_m(n, m);
}