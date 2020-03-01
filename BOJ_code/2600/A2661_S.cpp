// BOJ 2661 좋은수열
// Back tracking

#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int>& seq) {
	for (int i = 1; i <= seq.size() / 2; ++i) {
		for (int j = 0; j < seq.size() - i; ++j) {
			bool flag = true;
			if (j + 2 * i - 1 >= seq.size()) break;
			for (int k = j, l = j + i; k - j + 1 <= i; ++k, ++l)
				if (seq[k] != seq[l]) {
					flag = false;
					break;
				}
			if (flag) return false;
		}
	}
	return true;
}
void good(int n, vector<int>& seq, vector<int>& ans) {
	if (seq.size() == n) {
		ans = seq;
		return;
	}

	for (int i = 1; i <= 3; ++i) {
		if (seq[seq.size() - 1] != i) {
			seq.push_back(i);
			if (check(seq))
				good(n, seq, ans);
			seq.pop_back();
			if (ans.size()) return;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	vector<int> seq, ans;
	cin >> n;

	for (int i = 1; i <= 3; ++i) {
		seq.push_back(i);
		good(n, seq, ans);
		seq.pop_back();

		if (ans.size()) break;
	}

	for (int i = 0; i < n; ++i) cout << ans[i];
}