// BOJ 17588 Missing Numbers
// 구현

#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> in(n);
	for (int i = 0; i < n; ++i) cin >> in[i];

	vector<int> ans;
	int t = 1;
	for (int i = 0; i < n; ++i) {
		while (t < in[i]) ans.push_back(t++);
		t++;
	}

	if (ans.empty()) cout << "good job";
	else for (int x : ans) cout << x << '\n';
}