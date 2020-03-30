// BOJ 2568 ภüฑ๊มู - 2
// lis

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<pii> con(n);
	for (int i = 0; i < n; ++i) cin >> con[i].first >> con[i].second;
	sort(con.begin(), con.end());

	int last;
	vector<int> lis, mx(n);
	for (int i = 0; i < n; ++i) {
		if (lis.empty() || lis.back() < con[i].second) {
			mx[i] = lis.size();
			lis.push_back(con[i].second);
			last = i;
		}
		else {
			int idx = lower_bound(lis.begin(), lis.end(), con[i].second) - lis.begin();
			mx[i] = idx;
			lis[idx] = con[i].second;
		}
	}

	int ans = lis.size();
	vector<int> res = { con[last].first };
	for (int i = last - 1, j = ans - 2, k = last; i >= 0; --i) {
		if (mx[i] == j && con[i].second < con[k].second) {
			res.push_back(con[i].first);
			j--;
			k = i;
		}
	}

	cout << n - ans << '\n';
	for (int i = 0, j = res.size() - 1; i < n; ++i) {
		if (con[i].first == res[j]) j--;
		else cout << con[i].first << '\n';
	}
}