// BOJ 14610 좋은 대회
// greedy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vector<int> score(n), cmplt(n), cnt(m);
	vector<vector<int>> solve(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		cin >> score[i];

		if (score[i] == m || score[i] == 0) {
			cout << "NO";
			return 0;
		}

		for (int j = 0; j < m; ++j) {
			cin >> solve[i][j];
			if (solve[i][j] == 1)
				score[i]--, cnt[j]++;
		}

		if (!score[i])
			cmplt[i] = m;
		else {
			for (int j = 0; j < m; ++j)
				if (solve[i][j] == -1) {
					cmplt[i] = j;
					break;
				}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (cmplt[i] == m) continue;
		for (int j = cmplt[i]; j < m; ++j) {
			if (score[i] && !cnt[j]) {
				score[i]--;
				cnt[j]++;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < m; ++i)
		ans += (cnt[i] == 0);

	if (!ans) cout << "YES";
	else cout << "NO";
}