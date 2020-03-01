// BOJ 1202 º¸¼® µµµÏ
// gready algorithm

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<pii > jewel(n);
	for (int i = 0; i < n; ++i) cin >> jewel[i].first >> jewel[i].second;
	sort(jewel.begin(), jewel.end());

	vector<int> bag(k);
	for (int i = 0; i < k; ++i) cin >> bag[i];
	sort(bag.begin(), bag.end());

	ll ans = 0;
	priority_queue<int> pq;
	for (int i = 0, j = 0; i < k; ++i) {
		while (j < n && jewel[j].first <= bag[i])
			pq.push(jewel[j++].second);
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}