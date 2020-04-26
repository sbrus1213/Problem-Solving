// BOJ 15656 N°ú M (7)
// Backtracking

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int seq[10];
vector<int> ans;

void n_m(int n, int m) {
	if (ans.size() == m) {
		for (int x : ans)
			cout << x << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; ++i) {
		ans.push_back(seq[i]);
		n_m(n, m);
		ans.pop_back();
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> seq[i];
	sort(seq, seq + n);

	n_m(n, m);
}