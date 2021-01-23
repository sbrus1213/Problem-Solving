// 16207 직사각형
// Greedy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> len(n);
	for (int &li : len) cin >> li;
	sort(len.rbegin(), len.rend());

	vector<int> cand;
	for (int i = 0; i < n - 1; ++i) {
		if (len[i] == len[i + 1] || len[i] - 1 == len[i + 1]) {
			cand.push_back(len[i + 1]);
			i++;
		}
	}

	ll ans = 0;
	for (int i = 1; i < cand.size(); i += 2) {
		ans += 1LL * cand[i - 1] * cand[i];
	}
	cout << ans;
}