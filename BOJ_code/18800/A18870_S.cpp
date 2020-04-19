// BOJ 18870 ÁÂÇ¥¾ÐÃà
// sort

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<pii> seq(n);
	for (int i = 0; i < n; ++i) {
		cin >> seq[i].first;
		seq[i].second = i;
	}
	sort(seq.begin(), seq.end(), [](pii a, pii b) {
		return a.first < b.first;
		});

	map<int, int> dic;
	vector<int> ans(n);
	for (int i = 0, j = 1; i < n; ++i) {
		if (!dic[seq[i].first]) dic[seq[i].first] = j++;
		ans[seq[i].second] = dic[seq[i].first] - 1;
	}

	for (int x : ans) cout << x << ' ';
}