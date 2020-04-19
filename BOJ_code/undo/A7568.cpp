// BOJ 7568 µ¢Ä¡
// Brute Force

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<pii > man(n);
	for (int i = 0; i < n; ++i) cin >> man[i].first >> man[i].second;

	vector<pii> cnt(n);
	for (int i = 0; i < n; ++i) {
		cnt[i].second = i;
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			if (man[i].first > man[j].first&& man[i].second > man[j].second) cnt[i].first++;
		}
	}

	sort(cnt.begin(), cnt.end(), [](pii a, pii b) {
		return a.first > b.first;
		});
	int rank = 1;
	for (int i = 0; i < n;) {
		int t = cnt[i].first, id = i;
		while (i < n && cnt[i].first == t)
			i++;
		for (int j = id; j < i; ++j)
			cnt[j].first = rank;
		rank += i - id;
	}

	sort(cnt.begin(), cnt.end(), [](pii a, pii b) {
		return a.second < b.second;
		});
	for (int i = 0; i < n; ++i) cout << cnt[i].first << ' ';
}