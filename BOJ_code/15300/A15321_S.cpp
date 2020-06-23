// BOJ 15321 이상한 토너먼트
// greedy

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> X(n);
	for (int& xi : X) cin >> xi;

	int ans = 0;
	for (int i = 1; i < n; ++i) {
		int mn = *min_element(X.begin(), X.end());

		vector<int> tmp;
		for (int j = 0; j < X.size(); ++j) {
			if (X[j] != mn) tmp.push_back(X[j]);
			else {
				if (j == 0)
					ans += X[j + 1] - X[j];
				else if (j == X.size() - 1)
					ans += X[j - 1] - X[j];
				else ans += min(X[j + 1] - X[j], X[j - 1] - X[j]);
			}
		}

		X.clear();
		for (int x : tmp) X.push_back(x);
	}
	cout << ans;
}