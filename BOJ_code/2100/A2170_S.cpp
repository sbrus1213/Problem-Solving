// BOJ 2170 ¼± ±ß±â
// line sweeping

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

	vector<pii > p(n);
	for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
	sort(p.begin(), p.end());

	int l = p[0].first, r = p[0].second, ans = 0;
	for (int i = 1; i < n; ++i) {
		if (r < p[i].first) {
			ans += r - l;
			l = p[i].first, r = p[i].second;
		}
		else r = max(r, p[i].second);
	}
	ans += r - l;

	cout << ans;
}