// BOJ 15922 아우으 우아으이야!!
// line sweeping

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<pii> line(n);
	for (int i = 0; i < n; ++i)cin >> line[i].first >> line[i].second;

	int ans = 0, s, e;
	for (int i = 0; i < n;) {
		s = line[i].first;
		e = line[i].second;
		while (i < n && e >= line[i].first)
			e = max(e, line[i++].second);
		ans += e - s;
	}
	cout << ans;
}