// BOJ 15651 N°ú M (3)
// Backtracking

#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;

void n_m(int n, int m) {
	if (ans.size() == m) {
		for (int x : ans)
			cout << x << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; ++i) {
		ans.push_back(i);
		n_m(n, m);
		ans.pop_back();
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	n_m(n, m);
}